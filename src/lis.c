/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:04 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:30:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

/*	- copies elements of the 'stack' to array and returns it
	- memmory for the array is allocated
*/
int *stack_to_array(Stack *stack) {
	int *arr;
	int i;
	Node *i_node;

	arr = (int*)ft_calloc(stack->length, sizeof(int));
	if(!arr)
		return (NULL);
	i = 0;
	i_node = stack->top;
	while(i < stack->length) {
		arr[i] = i_node->data;
		i_node = i_node->next;
		i++;
	}
	return (arr);
}

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