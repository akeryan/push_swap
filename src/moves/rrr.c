/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:00 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 12:44:20 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//rrr : rra and rrb at the same time.
void	rrr(t_Twix *twix)
{
	twix->a.top = twix->a.top->prev;
	update_positions(&twix->a);
	twix->b.top = twix->b.top->prev;
	update_positions(&twix->b);
	printf("rrr\n");
}
