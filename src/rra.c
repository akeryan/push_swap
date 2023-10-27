/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:25:11 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
int rra(Twix *twix) {
	if(!twix)
		return (1);

	twix->a.top = twix->a.top->prev;
	update_positions(&twix->a);

	if(PRINT == 1)
		printf("rra\n");
	return (0);	
}
