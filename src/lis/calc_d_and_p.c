/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_d_and_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:57:43 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:57:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// calculates 'd' and 'p' variables of Lis_vars
void calc_d_and_p (Lis_vars *vars, Stack *stack) {
	Node *i_node;
	int i;
	int j;

	vars->s_arr = stack_to_array(stack); // copy stack to the s_arr array
	i = 0;
	i_node = stack->top;
	while(i < stack->length) {
		j = 0;
		while(j < i) {
			if(vars->s_arr[j] < vars->s_arr[i] && vars->d[i] < vars->d[j] + 1) {
				vars->d[i] = vars->d[j] + 1;
				vars->p[i] = j;
			}
			j++;
		}
		i++;
	}	
}