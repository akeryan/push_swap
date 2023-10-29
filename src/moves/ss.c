/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:34 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 12:45:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//ss : sa and sb at the same time.
void	ss(t_Twix *twix)
{
	int	temp1;
	int	temp2;

	temp1 = pop(&twix->a);
	temp2 = pop(&twix->a);
	push(&twix->a, temp1);
	push(&twix->a, temp2);
	temp1 = pop(&twix->b);
	temp2 = pop(&twix->b);
	push(&twix->b, temp1);
	push(&twix->b, temp2);
	printf("ss\n");
}
