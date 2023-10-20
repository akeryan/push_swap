#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdbool.h>
#include "../libft/libft.h"

typedef struct Node {
	int data;
	int score;
	int pos;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct Stack {
	Node *top;
	int length;
} Stack;

typedef struct Twix{
	Stack a;
	Stack b;
} Twix;

//parsing.c
void parsing(int argc, char **argv, Stack *stack);
bool enough_arguments(int argc);
void check_and_push(char **str, Stack *stack);
int is_duplicate(Stack *stack, int a);

//stack.c
void init_stack(Stack *stack);
Node *malloc_node();
bool is_empty(Stack *stack);
int stack_length(Stack *stack);
void print_stack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void update_positions(Stack *stack);

//Twix
void init_twix(Twix *twix);
int sa(Twix *twix);
int sb(Twix *twix);
int ss(Twix *twix);
int pb(Twix *twix);
int pa(Twix *twix);
int ra(Twix *twix);
int rb(Twix *twix);
int rr(Twix *twix);
int rra(Twix *twix);
int rrb(Twix *twix);
int rrr(Twix *twix);

//utils.c
size_t	my_strlen(const char *str);

//push_swap
void push_swap(Twix *twix);
int search_for_isertion_point(Stack *stack, int val);

#endif