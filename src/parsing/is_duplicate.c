/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:27:53 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 09:45:06 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//cheks whether value 'a' already present in 'stack'
int	is_duplicate(t_node *stack, int a)
{
	t_node	*current_node;

	if (!stack)
	{
		printf("Error - is_duplicates(): stack is NULL\n");
		return (-1);
	}
	current_node = stack;
	while (42)
	{
		if (current_node->data == a)
		{
			printf("Error\n");
			exit (1);
		}
		if (current_node->next == stack)
			break ;
		current_node = current_node->next;
	}
	return (0);
}
