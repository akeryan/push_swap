/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:07 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 14:56:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Creates and returns a variable of type t_Node and allocates memory for it
t_Node	*malloc_node(void)
{
	t_Node	*new_node;

	new_node = (t_Node *)malloc(sizeof(t_Node));
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
