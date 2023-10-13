/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:32:03 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/20 19:04:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlist;
	t_list	*newnode;

	if (!lst)
		return (NULL);
	temp = lst;
	newlist = NULL;
	while (temp)
	{
		newnode = ft_lstnew(f(temp->content));
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			return (newlist);
		}
		ft_lstadd_back(&newlist, newnode);
		temp = temp->next;
	}
	return (newlist);
}
