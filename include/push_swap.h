/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 17:50:37 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_Node
{
	int				data;
	int				pos;
	struct s_Node	*next;
	struct s_Node	*prev;
}	t_Node;

typedef struct s_Stack {
	t_Node	*top;
	int		length;
}	t_Stack;

typedef struct s_Twix {
	t_Stack	a;
	t_Stack	b;
}	t_Twix;

typedef struct s_Int_array {
	int	*array;
	int	length;
}	t_Int_array;

// d[i] is the length of the 'lis' that ends at the s_arr[i] 
// p[i] is the index j of the second last element in 'lis' ending in 'i'. 
// s_arr (stack_array): array for keeping the stack
// max_lis_ix is an index of maximum value in 'd'
// lis_restored is an array to keep restored 'lis'
typedef struct s_Lis_vars {
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
void		stack_to_array(t_Stack *stack, int *array);

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
int			*cheapest_push(t_Stack *stack_a, t_Stack *stack_b);
int			sumup_array(int *rots, int len);
void		clean(t_Twix *twix);

//lis
t_Int_array	*lis(t_Stack *stack);

//sorting
int			is_sorted(t_Node *start);
t_Node		*is_pseudo_sorted(t_Stack *stack);
t_Node		*min_element_in_stack(t_Stack *stack);

#endif