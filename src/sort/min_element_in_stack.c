/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_element_in_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:23 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 10:57:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// searches for and returns the minimal element of the 'stack'
t_node	*min_element_in_stack(t_node *stack)
{
	t_node	*this;
	t_node	*min;

	if (!stack)
		return (NULL);
	this = stack;
	min = stack;
	while (42)
	{
		if (this->data < min->data)
			min = this;
		if (this->next == stack)
			break ;
		this = this->next;
	}
	return (min);
}
