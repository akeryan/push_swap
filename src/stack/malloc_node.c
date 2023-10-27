/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:07 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:16:10 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Creates and returns a variable of type Node and allocates memory for it
Node *malloc_node() {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node) {
		fprintf(stderr, "Error - malloc_node(): Allocation for new node failed\n");
		exit(1);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = 0;
	return new_node;
}