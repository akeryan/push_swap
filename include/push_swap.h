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

//input_validation.c
bool parsing(int argc, char **argv, Stack *stack_a);
bool enough_arguments(int argc);
int check_and_push(char **str, Stack *stack);

//stack.c
void initialize(Stack *stack);
bool is_empty(Stack *stack);
void print_stack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);

//utils.c
size_t	my_strlen(const char *str);

#endif