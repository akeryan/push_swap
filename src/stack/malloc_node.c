/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:07 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 19:21:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Creates and returns a variable of type t_node and allocates memory for it
t_node	*malloc_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		fprintf(stderr, "Error - malloc_node(): Allocation failed\n");
		exit(1);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = 0;
	return (new_node);
}
