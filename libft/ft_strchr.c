/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:30:10 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/09 13:30:10 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	t;
	int				i;

	i = 0;
	t = c;
	while (s[i])
	{
		if (s[i] == t)
			return ((char *)&s[i]);
		i++;
	}
	if (t == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
