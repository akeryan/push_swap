/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pseudo_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:02:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 08:34:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- checks whether 'stack' is pseudo-sorted
	- pseudo-sorted means that since 'stack' is a circular linked list, 
	it is sorted starting from some element of the stack
*/

t_node	*is_pseudo_sorted(t_stack *stack)
{
	t_node	*min;
	int		result;

	min = min_element_in_stack(stack);
	result = is_sorted(min);
	if (result == -1 || result == 0)
		return (NULL);
	return (min);
}
