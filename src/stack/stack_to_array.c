/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 13:57:47 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- copies elements of the 'stack' to array and returns it
	- memmory for the array is allocated
*/
int	*stack_to_array(t_stack *stack, t_node *start)
{
	int		i;
	int		*arr;
	t_node	*tmp;

	if (!arr)
		return ;
	i = 0;
	arr = (int *)malloc(stack->length * sizeof(int));
	tmp = NULL;
	while (tmp != start)
	{
		if (!tmp)
			tmp = start;
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
