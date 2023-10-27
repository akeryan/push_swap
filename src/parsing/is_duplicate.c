/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:27:53 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:27:55 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//cheks whether value 'a' already present in 'stack'
int is_duplicate(Stack *stack, int a) {
	Node *current_node;

	if(!stack){
		printf("Error - is_duplicates(): stack is NULL\n");
		exit(0);
	}

	if(!stack->top)
		return (0);
		
	current_node = stack->top;
	while(42) {
		if(current_node->data == a) {
			printf("Error\n");
			return (1);
		}
		if(current_node->next == stack->top)
			break;
		current_node = current_node->next;
	}
	return (0);
}
 