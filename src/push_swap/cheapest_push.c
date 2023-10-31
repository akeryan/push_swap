/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:42:56 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 17:54:24 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int		search_for_insertion_location(t_stack *stack, int val);
static int		*rot_ops(int loc_a, int loc_b, int len_a, int len_b);
static t_node	*cheap_foo(t_stack *s_a, t_stack *s_b, t_node *this_node);

/*	searches for an element in stack 'b' that 'costs' the least
	to push to stack 'a' in terms of number of operations (e.g. ra, rr, ...)
*/
int	*cheapest_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*this_node;
	t_node	*cheap_node;
	int		v;
	int		*rots;

	this_node = stack_b->top;
	cheap_node = cheap_foo(stack_a, stack_b, this_node);
	v = search_for_insertion_location(stack_a, cheap_node->data);
	rots = rot_ops(v, cheap_node->pos, stack_a->length, stack_b->length);
	return (rots);
}

static t_node	*cheap_foo(t_stack *s_a, t_stack *s_b, t_node *this_node)
{
	t_node	*ch_node;
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

//searches in 'stack' the correct position where to place 'val'
static int	search_for_insertion_location(t_stack *stack, int val)
{
	t_node	*this_node;
	t_node	*max_val_node;
	int		i;

	if (!stack || !stack->top)
		return (-1);
	i = 0;
	max_val_node = stack->top;
	this_node = stack->top;
	while (i++ < stack->length)
	{
		if (val < this_node->data && val > this_node->prev->data)
			return (this_node->pos);
		if (max_val_node->data > this_node->data)
			max_val_node = this_node;
		this_node = this_node->next;
	}
	return (max_val_node->pos);
}

/*	- This function returns an array of size 6, that contains number of steps
	that each of the stacks needs to be rotated in order to perform placement 
	of the element from stack_b to stack_a
	- index '0' indicates number of times both stacks to be rotated forward 'rr'
	- index '1' indicates number of times both stacks to be rotated backward 'rrr'
	- index '2' indicates number of times stack_a to be rotated forward 'ra' 
	- index '3' indicates number of times stack_a to be rotated backward 'rra' 
	- index '4' indicates number of times stack_b to be rotated forward 'rb' 
	- index '5' indicates number of times stack_b to be rotated backward 'rrb' 
	*/
static int	*rot_ops(int loc_a, int loc_b, int len_a, int len_b)
{
	int	*rotations;

	rotations = (int *)ft_calloc(6, sizeof(int));
	check_allocation(rotations);
	if (loc_a <= len_a - loc_a + 1)
		rotations[2] = loc_a;
	else
		rotations[3] = len_a - loc_a;
	if (loc_b <= len_b - loc_b + 1)
		rotations[4] = loc_b;
	else
		rotations[5] = len_b - loc_b;
	if (rotations[2] > 0 && rotations[4] > 0)
	{
		rotations[0] = min(rotations[2], rotations[4]);
		rotations[2] -= rotations[0];
		rotations[4] -= rotations[0];
	}
	if (rotations[3] > 0 && rotations[5] > 0)
	{
		rotations[1] = min(rotations[3], rotations[5]);
		rotations[3] -= rotations[1];
		rotations[5] -= rotations[1];
	}
	return (rotations);
}
