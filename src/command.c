/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:54:40 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/16 17:07:13 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*find_env_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) && envp[i])
		i++;
	if (!envp[i])
		return (NULL);
	return (&envp[i][5]);
}

char	*find_the_path(char *command, char **env_path)
{
	char	*real_path;
	int		i;

	i = 0;
	command = ft_strjoin("/", command);
	if (!command)
		return (NULL);
	while (i != -1 && env_path[i])
	{
		real_path = ft_strjoin(env_path[i], command);
		if (!real_path)
		{
			free(command);
			return (NULL);
		}
		i++;
		if (!access(real_path, F_OK))
			i = -1;
		else
			free(real_path);
	}
	free(command);
	if (i == -1)
		return (real_path);
	return (NULL);
}

char	*whereis(char *command, char **env_path, char *split_cmd)
{
	if (!split_cmd || !command[0])
		return (NULL);
	if (access(command, F_OK) && env_path)
		return (find_the_path(split_cmd, env_path));
	else
		return (ft_strdup(command));
}

char	**get_the_command(char *command, char **env_path)
{
	char	**split_cmd;
	char	**cmd;
	int		i;

	split_cmd = ft_split(command, ' ');
	if (!split_cmd)
		return (NULL);
	i = 0;
	while (split_cmd[i])
		i++;
	cmd = malloc((i + 2) * sizeof(char *));
	if (!cmd)
	{
		ft_freeee(split_cmd, i);
		return (NULL);
	}
	cmd[0] = whereis(command, env_path, split_cmd[0]);
	i = 0;
	while (split_cmd[i++])
		cmd[i] = split_cmd[i - 1];
	cmd[i] = NULL;
	free(split_cmd);
	return (cmd);
}
