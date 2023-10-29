/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:18:18 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 15:48:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pops and returns the value from the top node of the 'stack'
int	pop(t_Stack *stack)
{
	int		value;
	t_Node	*temp;

	if (!stack)
	{
		fprintf(stderr, "Error - pop(): stack is null");
		exit(1);
	}
	if (is_empty(stack))
	{
		printf("Error - pop(): t_Stack is empty\n");
		return (-1);
	}
	temp = stack->top;
	value = temp->data;
	pop_foo(stack);
	stack->length--;
	update_positions(stack);
	return (value);
}

void	pop_foo(t_Stack *stack)
{
	t_Node	*temp;

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
			temp = stack->top;
			stack->top->next->prev = stack->top->prev;
			stack->top->prev->next = stack->top->next;
		}
		stack->top = stack->top->next;
	}
}
