/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:42:56 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/29 14:55:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	searches for an element in stack 'b' that 'costs' the least
	to push to stack 'a' in terms of number of operations (e.g. ra, rr, ...)
*/
int	*cheapest_push(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*this_node;
	t_Node	*cheap_node;
	int		v;
	int		*rots;

	this_node = stack_b->top;
	cheap_node = cheap(stack_a, stack_b, this_node);
	v = search_for_insertion_location(stack_a, cheap_node->data);
	rots = rot_ops(v, cheap_node->pos, stack_a->length, stack_b->length);
	return (rots);
}

t_Node	*cheap(t_Stack *s_a, t_Stack *s_b, t_Node *this_node)
{
	t_Node	*ch_node;
	int		steps_count;
	int		loc;
	int		*rots;	
	int		min_ops;

	min_ops = INT_MAX;
	while (42)
	{
		loc = search_for_insertion_location(s_a, this_node->data);
		rots = rot_ops(loc, this_node->pos, s_a->length, s_b->length);
		steps_count = sumup_array(rots, (int)6);
		free(rots);
		if (steps_count < min_ops)
		{
			min_ops = steps_count;
			ch_node = this_node;
		}
		if (this_node->next == s_b->top)
			break ;
		this_node = this_node->next;
	}
	return (ch_node);
}
