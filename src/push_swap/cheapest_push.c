/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:42:56 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:42:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	searches for an element in stack 'b' that 'costs' the least to push to stack 'a'
	in terms of number of operations (e.g. ra, rr, ...)
*/
int *cheapest_push(Stack *stack_a, Stack *stack_b) {
	int loc;
	int min_ops;
	Node *this_node;
	Node *cheap_node;
	int *rotations;
	int steps_count;

	this_node = stack_b->top;
	cheap_node = stack_b->top;
	min_ops = INT_MAX;

	while(42) {
		loc = search_for_insertion_location(stack_a, this_node->data);
		rotations = rotation_options(loc, this_node->pos, stack_a->length, stack_b->length);
		steps_count = sumup_rotations(rotations); 
		if(steps_count < min_ops) {
			min_ops = steps_count; 
			cheap_node = this_node;
		}
		if(this_node->next == stack_b->top)
			break;
		this_node = this_node->next;
	}
	loc = search_for_insertion_location(stack_a, cheap_node->data);
	rotations = rotation_options(loc, cheap_node->pos, stack_a->length, stack_b->length);
	return rotations;
}