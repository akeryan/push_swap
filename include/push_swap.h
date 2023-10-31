/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 10:02:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_twix {
	t_node	*a;
	t_node	*b;
}	t_twix;

typedef struct s_int_array {
	int	*array;
	int	length;
}	t_int_array;

// d[i] is the length of the 'lis' that ends at the s_arr[i] 
// p[i] is the index j of the second last element in 'lis' ending in 'i'. 
// s_arr (stack_array): array for keeping the stack
// max_lis_ix is an index of maximum value in 'd'
// lis_restored is an array to keep restored 'lis'
typedef struct s_lis_vars {
	int			*d;	
	int			*p;	
	int			*s_arr;
	int			max_lis_ix;
	t_int_array	*lis_restored;
}	t_lis_vars;

//parsing.c
void		parsing(int argc, char **argv, t_node *stack);
void		check_and_push(char **str, t_node *stack);
int			is_duplicate(t_node *stack, int a);

//stack.c
t_node		*new_node(int value);
void		print_stack(t_node *stack);
void		push(t_node *stack, int value);
void		push_foo(t_node *stack, t_node *new_node);
int			pop(t_stack *stack);
int			peek(t_stack *stack);
void		balance(t_twix *twix, t_node *foo);
void		pop_foo(t_stack *stack);
void		free_stack(t_stack *stack);
void		stack_to_array(t_stack *stack, int *array);

//t_twix
void		init_twix(t_twix *twix);
void		sa(t_twix *twix);
void		sb(t_twix *twix);
void		ss(t_twix *twix);
void		pb(t_twix *twix);
void		pa(t_twix *twix);
void		ra(t_twix *twix);
void		rb(t_twix *twix);
void		rr(t_twix *twix);
void		rra(t_twix *twix);
void		rrb(t_twix *twix);
void		rrr(t_twix *twix);

//utils.c
void		check_allocation(void *ptr);
size_t		my_strlen(const char *str);
int			min(int a, int b);
int			max(int a, int b);

//push_swap
void		push_swap(t_twix *twix);
int			*cheapest_push(t_stack *stack_a, t_stack *stack_b);
int			sumup_array(int *rots, int len);
void		clean(t_twix *twix);

//lis
t_int_array	*lis(t_stack *stack);

//sorting
int			is_sorted(t_node *start);
t_node		*is_pseudo_sorted(t_stack *stack);
t_node		*min_element_in_stack(t_stack *stack);

#endif