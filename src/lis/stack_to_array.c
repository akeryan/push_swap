/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:54:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- copies elements of the 'stack' to array and returns it
	- memmory for the array is allocated
*/
int *stack_to_array(Stack *stack) {
	int *arr;
	int i;
	Node *i_node;

	arr = (int*)ft_calloc(stack->length, sizeof(int));
	if(!arr)
		return (NULL);
	i = 0;
	i_node = stack->top;
	while(i < stack->length) {
		arr[i] = i_node->data;
		i_node = i_node->next;
		i++;
	}
	return (arr);
}