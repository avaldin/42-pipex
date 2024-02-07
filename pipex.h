/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:55:41 by avaldin           #+#    #+#             */
/*   Updated: 2024/01/27 09:41:22 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	char			**cmd[2];
	char			**env_path;
	int				file_fd[2];
	int				pipe_fd[2];
	struct s_pipex	*next;
}							t_pipex;

char	*find_the_path(char *command, char **envp);
char	*find_env_path(char **envp);
char	**get_the_command(char *command, char **env_path);
void	process(char **argv, t_pipex *data, char **envp);
void	close_pid(pid_t child_pid, int fd[2]);
void	close_n_wait(t_pipex *data);
void	open_n_pipe(t_pipex *data, char **argv);
void	fail(t_pipex *data, char *name, int exit_num);
void	super_free(t_pipex *data);

#endif
