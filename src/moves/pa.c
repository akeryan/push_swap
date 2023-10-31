/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:39 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 19:22:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	pa (push a): Take the first element at the top of b 
	and put it at the top of a. Do nothing if b is empty.
*/
void	pa(t_twix *twix)
{
	if (twix->b.top)
	{
		push(&twix->a, pop(&twix->b));
		printf("pa\n");
	}
	else
		fprintf(stderr, "Error - pa: stack 'b' is empty\n");
}
