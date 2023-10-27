/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_insertion_location.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:41:26 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:41:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//searches in 'stack' the correct position where to place 'val'
int search_for_insertion_location(Stack *stack, int val) {
	Node *this_node;
	Node *max_val_node;
	int i;

	if(!stack)
		return (-1); //stack is null
	if(is_empty(stack))
		return (0);

	i = 0;
	max_val_node = stack->top;
	this_node = stack->top;
	while(i++ < stack->length) {
		if(val < this_node->data && val > this_node->prev->data)
			return (this_node->pos);
		if(max_val_node->data > this_node->data)
			max_val_node = this_node;
		this_node = this_node->next;
	}
	return max_val_node->pos;
	//return 0;
}