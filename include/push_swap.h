#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdbool.h>
#include "../libft/libft.h"

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct Stack {
	Node *top;
} Stack;

typedef struct Twix{
	Stack a;
	Stack b;
} Twix;

//input_validation.c
bool parsing(int argc, char **argv, Stack *stack);
bool enough_arguments(int argc);
int check_and_push(char **str, Stack *stack);

//stack.c
void init_stack(Stack *stack);
bool is_empty(Stack *stack);
void print_stack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);

//Twix
void init_twix(Twix *twix);
int sa(Twix *twix);
int pb(Twix *twix);
int pa(Twix *twix);
//utils.c
size_t	my_strlen(const char *str);

#endif