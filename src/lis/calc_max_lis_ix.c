/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_max_lis_ix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 13:52:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// calculates max_lis_ix variable of t_Lis_vars structure
void	calc_max_lis_ix(t_Lis_vars *vars, t_Stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = vars->d[0];
	vars->max_lis_ix = 0;
	while (i < stack->length)
	{
		if (vars->d[i] > j)
		{
			j = vars->d[i];
			vars->max_lis_ix = i;
		}
		i++;
	}
}
