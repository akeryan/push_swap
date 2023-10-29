/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:42:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 18:18:25 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	if the twix->a is not pseudo-sorted it can be passed to 'clean' function
	in order to keep only a subsequence that is sorted (in an ascending order)
	the rest of the elements are pushed to the stack 'b'
*/
void	clean(t_Twix *twix)
{
	t_Int_array	*lis_a;
	int			i;

	i = 0;
	lis_a = lis(&twix->a);
	clean_foo(twix, lis_a);
	while (twix->a.length > lis_a->length)
		pb(twix);
	free(lis_a);
}

void	clean_foo(t_Twix *twix, t_Int_array *lis_a)
{
	int	i;

	i = 0;
	if (lis_a->length > 1)
	{
		while (i < lis_a->length)
		{
			if (twix->a.top->data != lis_a->array[i])
				pb(twix);
			else
			{
				ra(twix);
				i++;
			}
		}
	}
}
