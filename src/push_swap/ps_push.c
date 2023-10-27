/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:44:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 21:08:53 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	Implements execution of operations (e.g. ra, rr, ...) in accordance with 
	the instruction listed in 'actions' array
*/

void ps_push(Twix *twix, int *actions) {
	int i;
	int j;

	void (*operation[])(Twix *) = {rr, rrr, ra, rra, rb, rrb};

	i = 0;
	if(sumup_array(actions, STEPS) > 0) {
		while(i < STEPS) {
			j = 0;
			while(j < actions[i])	{
				operation[i](twix);
				j++;
			}
			i++;
		}
	}
	pa(twix);
}