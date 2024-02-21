/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:40:01 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/21 11:22:11 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	fail(t_pipex *data, char *name, int exit_num)
{
	ft_putstr_fd("zsh: ", STDERR_FILENO);
	if (exit_num != 5)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	else
		ft_putstr_fd("command not found ", STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (name)
		ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (exit_num)
	{
		super_free(data, 0);
		exit(exit_num);
	}
}
