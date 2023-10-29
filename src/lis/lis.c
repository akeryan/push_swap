/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:04 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 12:31:51 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//	https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

// 'lis' - longest increasing subsequence
t_Int_array	*lis(t_Stack *stack)
{
	int			i;
	t_Lis_vars	vars;

	if (!init_lis_vars(&vars, stack))
		return (NULL);
	calc_d_and_p(&vars, stack);
	calc_max_lis_ix(&vars, stack);
	if (!restore_lis(&vars))
		return (NULL);
	i = 0;
	free(vars.s_arr);
	free(vars.d);
	free(vars.p);
	return (vars.lis_restored);
}
