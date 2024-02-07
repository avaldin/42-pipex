/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:18 by logname           #+#    #+#             */
/*   Updated: 2023/11/10 09:14:23 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if (n == 0)
		return (0);
	while (s1[i] && i + j <= n)
	{
		if (((char *)s1)[i + j] == ((char *)s2)[j] && s2[j])
			j++;
		else if (((char *)s2)[j] == '\0')
			return ((char *)&s1[i]);
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
