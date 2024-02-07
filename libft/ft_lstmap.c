/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:32:48 by avaldin           #+#    #+#             */
/*   Updated: 2023/11/20 09:32:48 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*save;
	void	*cont;

	save = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cont = f(lst->content);
		new = ft_lstnew(cont);
		if (new == NULL)
		{
			del(cont);
			ft_lstclear(&save, del);
			return (NULL);
		}
		ft_lstadd_back(&save, new);
		lst = lst->next;
	}
	return (save);
}
