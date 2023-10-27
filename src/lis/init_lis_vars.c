/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lis_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:56:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:56:50 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// initializes Lis_vars structure
int init_lis_vars(Lis_vars *vars, Stack *stack) {
	int i;

	int s_len = stack->length;
	vars->s_arr = (int*)ft_calloc(s_len, sizeof(int));
	vars->d = (int*)ft_calloc(s_len, sizeof(int)); 
	vars->p = (int*)ft_calloc(s_len, sizeof(int));
	if(!vars->d || !vars->p || !vars->s_arr) {
		fprintf(stderr, "Error - lis(): Allocation of memory has failed\n");
		return (0);
	}
	i = 0;
	while(i < s_len) {
		vars->d[i] = 1;
		vars->p[i] = -1;
		i++;
	}
	return (1);
}
