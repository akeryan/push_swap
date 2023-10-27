/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:25 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 09:53:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
int ra(Twix *twix) {
	if(!twix)
		return (1);

	twix->a.top = twix->a.top->next;
	update_positions(&twix->a);
	if(PRINT == 1)
		printf("ra()\n");
	return (0);	
}