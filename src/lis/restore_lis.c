/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:59:16 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:59:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// restores 'lis' 
int restore_lis(Lis_vars *vars) {
	int i;
	int pos;
	
	vars->lis_restored = (Int_array *)malloc(sizeof(Int_array));
	vars->lis_restored->array = (int *)ft_calloc(vars->d[vars->max_lis_ix], sizeof(int));
	if(!vars->lis_restored || !vars->lis_restored->array)
		return (0);
	vars->lis_restored->length = vars->d[vars->max_lis_ix];

	pos = vars->max_lis_ix;
	i = vars->d[pos] - 1;
	vars->lis_restored->array[i] = vars->s_arr[pos];
	while(vars->p[pos] != -1) {
		vars->lis_restored->array[--i] = vars->s_arr[vars->p[pos]];
		pos = vars->p[pos];
	}
	return (1);
}