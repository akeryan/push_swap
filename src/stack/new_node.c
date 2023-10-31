/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:07 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 10:31:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Creates and returns a variable of type t_node and allocates memory for it
t_node	*new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		fprintf(stderr, "Error - malloc_node(): Allocation failed\n");
		exit(1);
	}
	new_node->data = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}