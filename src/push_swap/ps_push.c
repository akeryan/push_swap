/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:44:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 14:22:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	Implements execution of operations (e.g. ra, rr, ...) in accordance with 
	the instruction listed in 'actions' array
*/

void	ps_push(t_Twix *twix, int *actions)
{
	void	(*operation[6])(t_Twix *);
	int		i;
	int		j;

	operation[0] = rr;
	operation[1] = rrr;
	operation[2] = ra;
	operation[3] = rra;
	operation[4] = rb;
	operation[5] = rrb;
	i = 0;
	if (sumup_array(actions, (int)6) > 0)
	{
		while (i < (int)6)
		{
			j = 0;
			while (j < actions[i])
			{
				operation[i](twix);
				j++;
			}
			i++;
		}
	}
	pa(twix);
}
