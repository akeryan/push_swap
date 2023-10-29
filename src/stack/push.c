/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:17:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 16:00:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pushes element 'value' on top of 'stack'
void	push(t_Stack *stack, int value)
{
	t_Node	*new_node;

	if (!stack)
	{
		fprintf(stderr, "Error - push(): stack is null");
		exit(1);
	}
	new_node = malloc_node();
	new_node->data = value;
	new_node->pos = 0;
	push_foo(stack, new_node);
	stack->top = new_node;
	stack->length++;
	update_positions(stack);
}

void	push_foo(t_Stack *stack, t_Node *new_node)
{
	if (!is_empty(stack))
	{
		new_node->next = stack->top;
		if (stack->top->next == stack->top)
		{
			new_node->prev = stack->top;
			stack->top->next = new_node;
			stack->top->prev = new_node;
		}
		else
		{
			new_node->prev = stack->top->prev;
			stack->top->prev->next = new_node;
			stack->top->prev = new_node;
		}
	}
	else
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
}
