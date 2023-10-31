/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 19:22:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	rb (rotate b): Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	rb(t_twix *twix)
{
	twix->b.top = twix->b.top->next;
	update_positions(&twix->b);
	printf("rb\n");
}
