/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_element_in_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:23 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:03:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// searches for and returns the minimal element of the 'stack'
Node *min_element_in_stack(Stack *stack) {
	Node *this;
	Node *min;

	if(!stack || !stack->top)
		return (NULL);
	
	this = stack->top;
	min = stack->top;
	while(42) {
		if(this->data < min->data)
			min = this;		
		if(this->next == stack->top)
			break;
		this = this->next;
	}
	return min;
}