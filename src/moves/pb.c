/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:58 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 10:39:10 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	pb (push b): Take the first element at the top of a 
	and put it at the top of b. Do nothing if a is empty.
*/
void	pb(t_Twix *twix)
{
	if (twix->a.top)
	{
		push(&twix->b, pop(&twix->a));
		printf("pb\n");
	}
	else
		fprintf(stderr, "Error - pb: stack 'a' is empty\n");
}
