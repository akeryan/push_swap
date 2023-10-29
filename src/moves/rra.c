/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 12:37:09 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rra(t_Twix *twix)
{
	twix->a.top = twix->a.top->prev;
	update_positions(&twix->a);
	printf("rra\n");
}
