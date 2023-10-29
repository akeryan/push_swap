/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:59:16 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 13:58:09 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// restores 'lis' 
int	restore_lis(t_Lis_vars *vars)
{
	int				i;
	int				pos;
	unsigned int	sz;

	sz = sizeof(int);
	vars->lis_restored = (t_Int_array *)malloc(sizeof(t_Int_array));
	vars->lis_restored->array = (int *)ft_calloc(vars->d[vars->max_lis_ix], sz);
	if (!vars->lis_restored || !vars->lis_restored->array)
		return (0);
	vars->lis_restored->length = vars->d[vars->max_lis_ix];
	pos = vars->max_lis_ix;
	i = vars->d[pos] - 1;
	vars->lis_restored->array[i] = vars->s_arr[pos];
	while (vars->p[pos] != -1)
	{
		vars->lis_restored->array[--i] = vars->s_arr[vars->p[pos]];
		pos = vars->p[pos];
	}
	return (1);
}
