#ifndef STACK_H
#define STACK_H

#include "stack.h"

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Stack
{
	Node *top;
} Stack;

void initialize(Stack *stack);
bool isEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);

#endif
