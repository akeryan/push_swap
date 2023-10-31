/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:17:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 09:54:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pushes element 'value' on top of 'stack'
void	push(t_node *stack, int value)
{
	t_node	*new;

	if (!stack)
	{
		fprintf(stderr, "Error - push(): stack is null");
		exit(1);
	}
	new = new_node(value);
	push_foo(stack, new);
}

void	push_foo(t_node *stack, t_node *new_node)
{
	if (stack)
	{
		new_node->next = stack;
		if (stack->next == stack)
		{
			new_node->prev = stack;
			stack->next = new_node;
			stack->prev = new_node;
		}
		else
		{
			new_node->prev = stack->prev;
			stack->prev->next = new_node;
			stack->prev = new_node;
		}
	}
	else
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	stack = new_node;
}
