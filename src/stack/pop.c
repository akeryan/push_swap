/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:18:18 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:18:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pops and returns the value from the top node of the 'stack'
int pop(Stack *stack)
{
	int value;
	Node *temp;

	if (!stack)
	{
		fprintf(stderr, "Error - pop(): stack is null");
		exit(1);
	}

	if(is_empty(stack)) {
		printf("Error - pop(): Stack is empty\n");
		return (-1);
	}

	temp = stack->top;
	value = temp->data;
	if(stack->top->next == stack->top) { // it means that there is only one node, which is top node
		stack->top = NULL;
	} else {
		if (stack->top->next == stack->top->prev) { // it means that there are only two nodes
			stack->top->next->next = stack->top->next;
			stack->top->prev->prev = stack->top->prev;
		} else {
			temp = stack->top;
			stack->top->next->prev = stack->top->prev;
			stack->top->prev->next = stack->top->next;
		}
		stack->top = stack->top->next;					
	}
	stack->length--;
	update_positions(stack);

	return value;
}