/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:19:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:19:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// after the operations 'push' or 'pop' updates the positions of the remaining nodes
void update_positions(Stack *stack) {
	Node *this_node;
	int i;

	if(!stack || is_empty(stack))
		return;

	i = 0;
	stack->top->pos = i;
	this_node = stack->top->next;
	while(this_node != stack->top) {
		this_node->pos = ++i;
		this_node = this_node->next;
	}
}