/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:25 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 20:51:38 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
void ra(Twix *twix) {
	twix->a.top = twix->a.top->next;
	update_positions(&twix->a);
	printf("ra\n");
}