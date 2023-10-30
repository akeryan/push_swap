/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lis_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:56:47 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 16:16:25 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// initializes t_Lis_vars structure
t_Lis_vars	*init_lis_vars(t_Stack *stack)
{
	t_Lis_vars	*vars;
	int			i;
	int			s_len;

	s_len = stack->length;
	vars = (t_Lis_vars *)malloc(sizeof(t_Lis_vars));
	vars->s_arr = (int *)ft_calloc(s_len, sizeof(int));
	vars->d = (int *)ft_calloc(s_len, sizeof(int));
	vars->p = (int *)ft_calloc(s_len, sizeof(int));
	if (!vars->d || !vars->p || !vars->s_arr)
	{
		fprintf(stderr, "Error - lis(): Allocation of memory has failed\n");
		return (NULL);
	}
	i = 0;
	while (i < s_len)
	{
		vars->d[i] = 1;
		vars->p[i] = -1;
		i++;
	}
	return (vars);
}
