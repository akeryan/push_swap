/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:42 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 08:34:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// prints values of 'stack' into a terminal
void	print_stack(t_stack *stack)
{
	t_node	*current_node;

	if (!stack || !stack->top)
	{
		fprintf(stderr, "Error - peek(): stack is null or is empty\n");
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
