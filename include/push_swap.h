/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 16:13:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct Node
{
	int			data;
	int			pos;
	struct Node	*next;
	struct Node	*prev;
}	t_Node;

typedef struct t_Stack {
	t_Node	*top;
	int		length;
}	t_Stack;

typedef struct Twix {
	t_Stack	a;
	t_Stack	b;
}	t_Twix;

typedef struct Int_array {
	int	*array;
	int	length;
}	t_Int_array;

// d[i] is the length of the 'lis' that ends at the s_arr[i] 
// p[i] is the index j of the second last element in 'lis' ending in 'i'. 
// s_arr (stack_array): array for keeping the stack
// max_lis_ix is an index of maximum value in 'd'
// lis_restored is an array to keep restored 'lis'
typedef struct Lis_vars {
	int			*d;	
	int			*p;	
	int			*s_arr;
	int			max_lis_ix;
	t_Int_array	*lis_restored;
}	t_Lis_vars;

//parsing.c
void		parsing(int argc, char **argv, t_Stack *stack);
void		check_and_push(char **str, t_Stack *stack);
int			is_duplicate(t_Stack *stack, int a);

//stack.c
void		init_stack(t_Stack *stack);
t_Node		*malloc_node(void);
bool		is_empty(t_Stack *stack);
void		print_stack(t_Stack *stack);
void		push(t_Stack *stack, int value);
void		push_foo(t_Stack *stack, t_Node *new_node);
int			pop(t_Stack *stack);
int			peek(t_Stack *stack);
void		update_positions(t_Stack *stack);
void		balance(t_Twix *twix, t_Node *foo);
void		pop_foo(t_Stack *stack);
void		free_stack(t_Stack *stack);

//t_Twix
void		init_twix(t_Twix *twix);
void		sa(t_Twix *twix);
void		sb(t_Twix *twix);
void		ss(t_Twix *twix);
void		pb(t_Twix *twix);
void		pa(t_Twix *twix);
void		ra(t_Twix *twix);
void		rb(t_Twix *twix);
void		rr(t_Twix *twix);
void		rra(t_Twix *twix);
void		rrb(t_Twix *twix);
void		rrr(t_Twix *twix);

//utils.c
void		check_allocation(void *ptr);
size_t		my_strlen(const char *str);
int			min(int a, int b);
int			max(int a, int b);

//push_swap
void		push_swap(t_Twix *twix);
int			search_for_insertion_location(t_Stack *stack, int val);
int			*rot_ops(int loc_a, int loc_b, int len_a, int len_b);
void		ps_push(t_Twix *twix, int *steps);
int			*cheapest_push(t_Stack *stack_a, t_Stack *stack_b);
t_Node		*cheap_foo(t_Stack *s_a, t_Stack *s_b, t_Node *this_node);
int			sumup_array(int *rots, int len);
void		clean(t_Twix *twix);
void		inject_back(t_Twix *twix);
void		clean_foo(t_Twix *twix, t_Int_array *lis_a);

//lis
t_Int_array	*lis(t_Stack *stack);
void		stack_to_array(t_Stack *stack, int *array);
t_Lis_vars	*init_lis_vars(t_Stack *stack);
void		calc_d_and_p(t_Lis_vars *vars, t_Stack *stack);
void		calc_max_lis_ix(t_Lis_vars *vars, t_Stack *stack);
int			restore_lis(t_Lis_vars *vars);

//sorting
int			is_sorted(t_Node *start);
t_Node		*is_pseudo_sorted(t_Stack *stack);
t_Node		*min_element_in_stack(t_Stack *stack);
void		three_sort(t_Twix *twix);
void		five_sort(t_Twix *twix);

#endif