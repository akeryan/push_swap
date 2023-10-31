/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:42 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 10:07:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// prints values of 'stack' into a terminal
void	print_stack(t_node *stack)
{
	t_node	*current_node;

	if (!stack)
	{
		fprintf(stderr, "Error - peek(): stack is null or is empty\n");
		return ;
	}
	current_node = NULL;
	while (current_node != stack)
	{
		if (!current_node)
			current_node = stack;
		printf("val: %d\n", current_node->data);
		current_node = current_node->next;
	}
}
