/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:40:01 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/16 17:07:16 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	fail(t_pipex *data, char *name, int exit_num)
{
	ft_putstr_fd("zsh: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (name)
		ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (exit_num)
	{
		super_free(data);
		exit(exit_num);
	}
}

void	close_pid(pid_t child_pid, int fd[2])
{
	if (child_pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	open_n_pipe(t_pipex *data, char **argv)
{
	data->file_fd[0] = open(argv[1], O_RDONLY);
	if (data->file_fd[0] == -1)
		fail(data, argv[1], 0);
	data->file_fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->file_fd[1] < 0)
		fail(data, argv[4], 0);
	pipe(data->pipe_fd);
}
