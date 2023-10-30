/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:19:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 09:22:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// after the operations 'push' or 'pop' updates positions of the nodes
void	update_positions(t_Stack *stack)
{
	t_Node	*this_node;
	int		i;

	if (!stack || is_empty(stack))
		return ;
	i = 0;
	this_node = stack->top;
	while (42)
	{
		this_node->pos = i++;
		this_node = this_node->next;
		if (this_node == stack->top)
			break ;
	}
}
