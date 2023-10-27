/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:00 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 20:53:29 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"

//rrr : rra and rrb at the same time.
void rrr(Twix *twix) {
	//rra
	twix->a.top = twix->a.top->prev;
	update_positions(&twix->a);
	//rrb
	twix->b.top = twix->b.top->prev;
	update_positions(&twix->b);

	printf("rrr\n");
}