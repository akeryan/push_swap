/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:04 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:59:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//	https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

// 'lis' - longest increasing subsequence
Int_array *lis(Stack *stack) {
	int i;
	Lis_vars vars;

	if(!init_lis_vars(&vars, stack)) //initialize 'vars'
		return (NULL);
	calc_d_and_p(&vars, stack); // calculate arrays 'd' and 'p'
	calc_max_lis_ix(&vars, stack); // calculate max_lis_ix value
	if(!restore_lis(&vars))
		return (NULL);

	i = 0;
	free(vars.s_arr);
	free(vars.d);
	free(vars.p);

    return vars.lis_restored;
}



 

 
