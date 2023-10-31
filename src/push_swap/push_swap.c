/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:08 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 21:47:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void		three_sort(t_twix *twix);
static void		five_sort(t_twix *twix);
static void		inject_back(t_twix *twix);
static void		ps_push(t_twix *twix, int *actions);

//manages the whole process of the push_swap program
void	push_swap(t_twix *twix)
{
	t_node	*min;

	if (twix->a.length == 3)
	{
		three_sort(twix);
		return ;
	}
	if (twix->a.length == 5)
	{
		five_sort(twix);
		return ;
	}
	min = is_pseudo_sorted(&twix->a);
	if (min)
	{
		balance(twix, min);
		return ;
	}
	clean(twix);
	inject_back(twix);
	min = is_pseudo_sorted(&twix->a);
	if (min)
		balance(twix, min);
}

// sorting algorithm for input of length 3
static void	three_sort(t_twix *twix)
{
	t_node	*temp;

	temp = is_pseudo_sorted(&twix->a);
	if (temp != NULL)
		return (balance(twix, temp));
	sa(twix);
	balance(twix, is_pseudo_sorted(&twix->a));
}

// sorting algorithm for input of length 5
static void	five_sort(t_twix *twix)
{
	t_node	*pos;

	pb(twix);
	pb(twix);
	three_sort(twix);
	inject_back(twix);
	pos = is_pseudo_sorted(&twix->a);
	if (pos)
		balance(twix, pos);
}

static void	inject_back(t_twix *twix)
{
	int	*rots;

	while (twix->b.length > 0)
	{
		rots = cheapest_push(&twix->a, &twix->b);
		ps_push(twix, rots);
		free(rots);
	}
}

/*	Implements execution of operations (e.g. ra, rr, ...) in accordance with 
	the instruction listed in 'actions' array
*/

static void	ps_push(t_twix *twix, int *actions)
{
	void	(*operation[6])(t_twix *);
	int		i;
	int		j;

	operation[0] = rr;
	operation[1] = rrr;
	operation[2] = ra;
	operation[3] = rra;
	operation[4] = rb;
	operation[5] = rrb;
	i = 0;
	if (sumup_array(actions, (int)6) > 0)
	{
		while (i < (int)6)
		{
			j = 0;
			while (j < actions[i])
			{
				operation[i](twix);
				j++;
			}
			i++;
		}
	}
	pa(twix);
}
