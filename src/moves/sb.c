/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:28 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 19:22:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void	sb(t_twix *twix)
{
	int	temp1;
	int	temp2;

	temp1 = pop(&twix->b);
	temp2 = pop(&twix->b);
	push(&twix->b, temp1);
	push(&twix->b, temp2);
	printf("sb\n");
}
