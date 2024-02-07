/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logname <logname@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:55:01 by logname           #+#    #+#             */
/*   Updated: 2023/11/15 09:55:01 by logname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_intalloc(unsigned int n, int s)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	str = malloc((i + 1 + s) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static void	ft_fillstr(unsigned int n, char *str, int *i)
{
	if (n < 10)
	{
		str[*i] = n + 48;
		*i = *i + 1;
	}
	else
	{
		ft_fillstr(n / 10, str, i);
		ft_fillstr(n % 10, str, i);
	}
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nbr;
	int				i;

	i = 0;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	else
		nbr = n;
	s = ft_intalloc(nbr, i);
	if (!s)
		return (NULL);
	s[0] = '-';
	ft_fillstr(nbr, s, &i);
	s[i] = '\0';
	return (s);
}
