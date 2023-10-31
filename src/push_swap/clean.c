/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:42:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 15:35:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	clean_foo(t_twix *twix, t_int_array *lis_a);

/*	if the twix->a is not pseudo-sorted it can be passed to 'clean' function
	in order to keep only a subsequence that is sorted (in an ascending order)
	the rest of the elements are pushed to the stack 'b'
*/
void	clean(t_twix *twix)
{
	t_int_array	*lis_a;

	lis_a = lis(&twix->a);
	printf("RESTORED ARRAY\n");
	for (int i = 0; i < lis_a->length; i++)
		printf("%d: %d\n", i, lis_a->array[i]);
	clean_foo(twix, lis_a);
	while (twix->a.length > lis_a->length)
		pb(twix);
	free(lis_a->array);
	free(lis_a);
}

static void	clean_foo(t_twix *twix, t_int_array *lis_a)
{
	int		i;
	int		j;
	t_node	*tmp;
	int		catch;

	j = 0;
	if (lis_a->length > 1)
	{
		tmp = NULL;
		while (j < twix->a.length)
		{
			if (!tmp)
				tmp = twix->a.top;
			i = 0;
			catch = 0;
			while (i < lis_a->length)
			{
				if (tmp->data == lis_a->array[i])
					catch = 1;
				i++;
			}
			if (catch == 1)
				ra(twix);
			else
				pb(twix);
			tmp = tmp->next;
			j++;
		}
	}
}