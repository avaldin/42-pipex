/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:44:33 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/09 11:03:13 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	isrc;
	size_t	idest;
	size_t	destlen;
	size_t	srclen;

	isrc = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	idest = destlen;
	if (size == 0)
		return (srclen);
	while (src[isrc] && idest < size - 1)
	{
		dest[idest] = src[isrc];
		idest++;
		isrc++;
	}
	dest[idest] = 0;
	if (size < idest)
		return (srclen + size);
	return (destlen + srclen);
}
