/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:21:00 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 15:01:40 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// works correctly only if the stack is sorted in an ascending order
// 'foo' pointer shows the node from which the stack should be balanced and 
// can be identified with help of is_pseudo_sorted() function
void	balance(t_Twix *twix, t_Node *foo)
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
