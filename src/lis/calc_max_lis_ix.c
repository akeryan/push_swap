/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_max_lis_ix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:58:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:58:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// calculates max_lis_ix variable of Lis_vars structure
void calc_max_lis_ix(Lis_vars *vars, Stack *stack) {
	int i;
	int j;

	i = 0;
    j = vars->d[0];
	vars->max_lis_ix = 0;
	while(i < stack->length) {
		if(vars->d[i] > j) {
			j = vars->d[i];
			vars->max_lis_ix = i;
		}
		i++;
	}
}