/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inject.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:40:13 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/29 09:56:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- This function injects elements from stack 'b' to stack 'a' 
	in there correct locatoins
	- Assumption is that stack 'a' is sorted (in an ascending order)
*/

void	inject_back(t_Twix *twix)
{
	int	*rots;

	while (twix->b.length > 0)
	{
		rots = cheapest_push(&twix->a, &twix->b);
		ps_push(twix, rots);
	}
}
