/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:46:49 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/13 10:46:49 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_findstart(char const *s1, char const *set)
{
	int	start;
	int	j;
	int	i;

	i = 0;
	j = 0;
	start = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			start++;
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (start);
}

static int	ft_findend(char const *s1, char const *set, int i)
{
	int	j;
	int	len;

	len = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			len++;
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	start = ft_findstart(s1, set);
	if (start >= (int)ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (s1[start + i])
		i++;
	len = i - ft_findend(s1, set, start + i - 1);
	str = ft_substr(s1, start, len);
	return (str);
}
