/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:54 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 20:53:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"
//rrb (reverse rotate b): Shift down all elements of stack a by 1. The last element becomes the first one.
void rrb(Twix *twix) {
	twix->b.top = twix->b.top->prev;
	update_positions(&twix->b);
	printf("rrb\n");
}