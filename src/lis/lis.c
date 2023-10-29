/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:04 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/29 13:29:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//	https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

// 'lis' - longest increasing subsequence
t_Int_array	*lis(t_Stack *stack)
{
	t_Lis_vars	*vars;
	t_Int_array *lis_restored;

	vars = init_lis_vars(stack);
	if (!vars)
		return (NULL);
	calc_d_and_p(vars, stack);
	calc_max_lis_ix(vars, stack);
	if (!restore_lis(vars))
		return (NULL);
	lis_restored = vars->lis_restored;
	free(vars->s_arr);
	free(vars->d);
	free(vars->p);
	free(vars);
	return (lis_restored);
}
