/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:20:37 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 10:33:45 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_len(t_node *stack)
{
	t_node	*tmp;
	int		len;

	if (!stack)
		return (0);
	len = 0;
	tmp = NULL;
	while (tmp != stack)
	{
		if (!tmp)
			tmp = stack;
		len++;
		tmp = tmp->next;
	}
	return (len);
}
