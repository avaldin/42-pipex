/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:53:51 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/31 11:37:17 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_cmd(t_pipex *data, char **envp)
{
	close(data->pipe_fd[1]);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		fail(data, "pipe dup", 6);
	close(data->pipe_fd[0]);
	if (dup2(data->file_fd[1], STDOUT_FILENO) == -1)
		fail(data, "file dup", 7);
	execve(data->cmd[1][0], &data->cmd[1][1], envp);
	fail(data, "execve", 8);
}

void	first_cmd(t_pipex *data, char **envp)
{
	close(data->pipe_fd[0]);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		fail(data, "pipe dup", 3);
	close(data->pipe_fd[1]);
	if (dup2(data->file_fd[0], STDIN_FILENO) == -1)
		fail(data, "file dup", 4);
	execve(data->cmd[0][0], &data->cmd[0][1], envp);
	fail(data, "execve", 5);
}

void	process(char **argv, t_pipex *data, char **envp)
{
	pid_t	child_pid;
	pid_t	child_pid2;

	open_n_pipe(data, argv);
	child_pid = fork();
	close_pid(child_pid, data->pipe_fd);
	if (!child_pid && data->file_fd[0] != -1 && data->cmd[0][0])
		first_cmd(data, envp);
	else if (child_pid)
	{
		child_pid2 = fork();
		close_pid(child_pid2, data->pipe_fd);
		if (!child_pid2 && data->file_fd[1] != -1 && data->cmd[1][0])
			second_cmd(data, envp);
		else if (child_pid2)
		{
			waitpid(child_pid, NULL, 0);
			waitpid(child_pid2, NULL, 0);
		}
	}
	super_free(data);
	exit(EXIT_SUCCESS);
}
