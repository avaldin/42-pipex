/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:53:51 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/21 11:18:14 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	second_cmd(t_pipex *data, char **envp, char *file)
{
	data->file_fd[1] = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->file_fd[1] < 0)
		fail(data, file, 0);
	if (data->cmd[1][0])
	{
		if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
			fail(data, "pipe dup", 6);
		if (dup2(data->file_fd[1], STDOUT_FILENO) == -1)
			fail(data, "file dup", 7);
		close(data->pipe_fd[1]);
		close(data->pipe_fd[0]);
		close(data->file_fd[1]);
		execve(data->cmd[1][0], &data->cmd[1][1], envp);
	}
	fail(data, NULL, 5);
}

void	first_cmd(t_pipex *data, char **envp, char *file)
{
	data->file_fd[0] = open(file, O_RDONLY);
	if (data->file_fd[0] == -1)
		fail(data, file, 0);
	if (data->cmd[0][0])
	{
		if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
			fail(data, "pipe dup", 3);
		if (dup2(data->file_fd[0], STDIN_FILENO) == -1)
			fail(data, "file dup", 4);
		close(data->pipe_fd[1]);
		close(data->pipe_fd[0]);
		close(data->file_fd[0]);
		fprintf(stderr, "%s\n", data->cmd[0][0]);
		execve(data->cmd[0][0], &data->cmd[0][1], envp);
		close(0);
		close(1);
	}
	fail(data, NULL, 5);
}

void	process(char **argv, t_pipex *data, char **envp)
{
	pid_t	child_pid;
	pid_t	child_pid2;

	if (pipe(data->pipe_fd) == -1)
		fail(data, "pipe", 10);
	child_pid = fork();
	if (child_pid == -1)
		fail(data, "fork", 9);
	if (child_pid == 0)
		first_cmd(data, envp, argv[1]);
	child_pid2 = fork();
	if (child_pid2 == -1)
		fail(data, "fork2", 11);
	if (child_pid2 == 0)
		second_cmd(data, envp, argv[4]);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	waitpid(child_pid, NULL, 0);
	waitpid(child_pid2, NULL, 0);
	super_free(data, -1);
	exit(EXIT_SUCCESS);
}
