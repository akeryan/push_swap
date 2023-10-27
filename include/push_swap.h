/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:51:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 21:07:37 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define STEPS	6
#define PRINT	1 // '1' - print, '0' - don't print

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct Node {
	int data;
	int pos;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct Stack {
	Node *top;
	int length;
} Stack;

typedef struct Twix {
	Stack a;
	Stack b;
} Twix;

typedef struct Int_array {
	int *array;
	int length; 
} Int_array;

typedef struct Lis_vars {
	int *d;	// d[i] is the length of the 'lis' that ends at the s_arr[i] 
	int *p;	// p[i] is the index j of the second last element in 'lis' ending in 'i'. 
	int *s_arr; //stack_array: array for keeping the stack
	int max_lis_ix; //index of maximum value in 'd'
	Int_array *lis_restored; //array to keep restored 'lis'
} Lis_vars;

//parsing.c
void parsing(int argc, char **argv, Stack *stack);
bool enough_arguments(int argc);
void check_and_push(char **str, Stack *stack);
int is_duplicate(Stack *stack, int a);

//stack.c
void init_stack(Stack *stack);
Node *malloc_node();
bool is_empty(Stack *stack);
void print_stack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void update_positions(Stack *stack);
void balance(Twix *twix, Node *foo);

//Twix
void init_twix(Twix *twix);
void sa(Twix *twix);
void sb(Twix *twix);
void ss(Twix *twix);
void pb(Twix *twix);
void pa(Twix *twix);
void ra(Twix *twix);
void rb(Twix *twix);
void rr(Twix *twix);
void rra(Twix *twix);
void rrb(Twix *twix);
void rrr(Twix *twix);

//utils.c
size_t	my_strlen(const char *str);
int min(int a, int b);
int max(int a, int b);

//push_swap
void push_swap(Twix *twix);
int search_for_insertion_location(Stack *stack, int val);
int *rotation_options(int loc_a, int loc_b, int len_a, int len_b);
void ps_push(Twix *twix, int *steps);
int *cheapest_push(Stack *stack_a, Stack *stack_b);
int sumup_array(int *rots, int len);
int clean(Twix *twix);
void inject_back(Twix *twix);

//lis
Int_array *lis(Stack *stack);
int *stack_to_array(Stack *stack);
int init_lis_vars(Lis_vars *vars, Stack *stack);
void calc_d_and_p (Lis_vars *vars, Stack *stack);
void calc_max_lis_ix(Lis_vars *vars, Stack *stack);
int restore_lis(Lis_vars *vars);

//sorting
int is_sorted(Node *start); 
Node *is_pseudo_sorted(Stack *stack);
Node *min_element_in_stack(Stack *stack);
void three_sort(Twix *twix);
void five_sort(Twix *twix);

#endif