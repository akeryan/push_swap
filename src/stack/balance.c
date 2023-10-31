/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:21:00 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 19:22:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// works correctly only if the stack is sorted in an ascending order
// 'foo' pointer shows the node from which the stack should be balanced and 
// can be identified with help of is_pseudo_sorted() function
void	balance(t_twix *twix, t_node *foo)
{
	int	pos;

	pos = foo->pos;
	if (pos <= twix->a.length / 2)
		while (pos-- > 0)
			ra(twix);
	else
	{
		pos = twix->a.length - pos;
		while (pos-- > 0)
			rra(twix);
	}
}
