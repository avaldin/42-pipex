/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:12:26 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/08 14:12:26 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (i + 1 < size)
			dst[i] = src[i];
		i++;
	}
	if (size)
	{
		if (size - 1 < i)
			dst[size - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (i);
}
