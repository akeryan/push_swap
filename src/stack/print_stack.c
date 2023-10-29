/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:42 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 14:57:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// prints values of 'stack' into a terminal
void	print_stack(t_Stack *stack)
{
	t_Node	*current_node;

	if (!stack)
	{
		fprintf(stderr, "Error - pring_stack(): stack is NULL\n");
		exit(0);
	}
	if (is_empty(stack))
	{
		fprintf(stderr, "Error - print_stack(): stack is empty\n");
		return ;
	}
	current_node = stack->top;
	printf("%d: %d\n", current_node->pos, current_node->data);
	while (current_node->next != stack->top)
	{
		current_node = current_node->next;
		printf("%d: %d\n", current_node->pos, current_node->data);
	}
}
