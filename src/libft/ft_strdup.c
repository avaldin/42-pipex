/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:16:03 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/13 09:16:03 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/pipex.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen((char *)s);
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (&str[0]);
}
