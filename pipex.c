/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:08:01 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/31 10:16:24 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_pipex *data)
{
	int	i;

	i = 0;
	if (data->cmd[0])
	{
		if (!data->cmd[0][0])
			i++;
		while (data->cmd[0][i])
			free(data->cmd[0][i++]);
		free(data->cmd[0]);
	}
	i = 0;
	if (data->cmd[1])
	{
		if (!data->cmd[1][0])
			i++;
		while (data->cmd[1][i])
			free(data->cmd[1][i++]);
		free(data->cmd[1]);
	}
}

void	super_free(t_pipex *data)
{
	int	i;

	free_cmd(data);
	i = 0;
	if (data->env_path)
	{
		while (data->env_path[i])
			free(data->env_path[i++]);
		free(data->env_path);
	}
	if (data->file_fd[0] != -1)
		close(data->file_fd[0]);
	if (data->file_fd[1] != -1)
		close(data->file_fd[1]);
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
}

void	data_set(t_pipex *data)
{
	data->cmd[1] = NULL;
	data->cmd[0] = NULL;
	data->env_path = NULL;
	data->file_fd[0] = -1;
	data->file_fd[1] = -1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	(void)argc;
	if (argc != 5)
		return (1);
	data_set(&data);
	if (envp[0])
	{
		data.env_path = ft_split(find_env_path(envp), ':');
		if (!data.env_path)
			return (2);
	}
	data.cmd[0] = get_the_command(argv[2], data.env_path);
	data.cmd[1] = get_the_command(argv[3], data.env_path);
	if (!data.cmd[0] || !data.cmd[1])
	{
		super_free(&data);
		return (3);
	}
	process(argv, &data, envp);
	super_free(&data);
	return (0);
}
