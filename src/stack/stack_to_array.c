/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 08:34:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- copies elements of the 'stack' to array and returns it
	- memmory for the array is allocated
*/
void	stack_to_array(t_stack *stack, int *arr)
{
	int		i;
	t_node	*i_node;

	if (!arr)
		return ;
	i = 0;
	i_node = stack->top;
	while (i < stack->length)
	{
		arr[i] = i_node->data;
		i_node = i_node->next;
		i++;
	}
}
