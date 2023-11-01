/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:18:18 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/01 07:46:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	pop_foo(t_stack *stack);

// pops and returns the value from the top node of the 'stack'
int	pop(t_stack *stack)
{
	int		value;

	if (!stack || !stack->top)
	{
		fprintf(stderr, "Error - peek(): stack is null or is empty\n");
		return (-1);
	}
	value = stack->top->data;
	pop_foo(stack);
	update_positions(stack);
	return (value);
}

static void	pop_foo(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	if (stack->top->next == stack->top)
		stack->top = NULL;
	else
	{
		if (stack->top->next == stack->top->prev)
		{
			stack->top->next->next = stack->top->next;
			stack->top->prev->prev = stack->top->prev;
		}
		else
		{
			stack->top->next->prev = stack->top->prev;
			stack->top->prev->next = stack->top->next;
		}
		stack->top = stack->top->next;
	}
	free(temp);
	stack->length--;
}
