/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:55:41 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/21 09:58:23 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
void	fail(t_pipex *data, char *name, int exit_num);
void	super_free(t_pipex *data, int k);

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	**ft_freeee(char **str, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif
