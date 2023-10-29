/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_d_and_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:57:43 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/29 12:35:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// calculates 'd' and 'p' variables of t_Lis_vars
void	calc_d_and_p(t_Lis_vars *vars, t_Stack *stack)
{
	int		i;
	int		j;

	stack_to_array(stack, vars->s_arr);
	i = 0;
	while (i < stack->length)
	{
		j = 0;
		while (j < i)
		{
			if (vars->s_arr[j] < vars->s_arr[i] && vars->d[i] < vars->d[j] + 1)
			{
				vars->d[i] = vars->d[j] + 1;
				vars->p[i] = j;
			}
			j++;
		}
		i++;
	}	
}
