/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:04 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 08:35:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//	https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

static t_lis_vars	*init_lis_vars(t_stack *stack);
static void			calc_d_and_p(t_lis_vars *vars, t_stack *stack);
static void			calc_max_lis_ix(t_lis_vars *vars, t_stack *stack);
static int			restore_lis(t_lis_vars *vars);

// 'lis' - longest increasing subsequence
t_int_array	*lis(t_stack *stack)
{
	t_lis_vars	*vars;
	t_int_array	*lis_restored;

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

// calculates 'd' and 'p' variables of t_lis_vars
static void	calc_d_and_p(t_lis_vars *vars, t_stack *stack)
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

// calculates max_lis_ix variable of t_lis_vars structure
static void	calc_max_lis_ix(t_lis_vars *vars, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = vars->d[0];
	vars->max_lis_ix = 0;
	while (i < stack->length)
	{
		if (vars->d[i] > j)
		{
			j = vars->d[i];
			vars->max_lis_ix = i;
		}
		i++;
	}
}

// initializes t_lis_vars structure
static t_lis_vars	*init_lis_vars(t_stack *stack)
{
	t_lis_vars	*vars;
	int			i;
	int			s_len;

	s_len = stack->length;
	vars = (t_lis_vars *)malloc(sizeof(t_lis_vars));
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

// restores 'lis' 
static int	restore_lis(t_lis_vars *vars)
{
	int				i;
	int				pos;
	unsigned int	sz;

	sz = sizeof(int);
	vars->lis_restored = (t_int_array *)malloc(sizeof(t_int_array));
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
