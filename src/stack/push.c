/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:17:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:17:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// pushes element 'value' on top of 'stack'
void push(Stack *stack, int value)
{
	if (!stack) {
		fprintf(stderr, "Error - push(): stack is null");
		exit(1);
	}

	Node *new_node = malloc_node();
	new_node->data = value;
	new_node->pos = 0;

	if(!is_empty(stack)){
		new_node->next = stack->top;
		if(stack->top->next == stack->top) { // it means that there is only one node, which is top node
			new_node->prev = stack->top;
			stack->top->next = new_node;
			stack->top->prev = new_node;
		} else { // stack->length > 1
			new_node->prev = stack->top->prev;
			stack->top->prev->next = new_node;
			stack->top->prev = new_node;
		}
	} else { // stack is empty
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	stack->top = new_node;
	stack->length++;
	update_positions(stack);
}