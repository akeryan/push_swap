#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "stack.h"

void initialize(Stack *stack) {
	if(stack == NULL) {
		printf("stack is null");
		exit(1);
	}
	stack->top = NULL;
}

bool isEmpty(Stack *stack) {
	if(stack == NULL) {
		printf("stack is null");
		exit(1);
	}
	return (stack->top == NULL);
}

void push(Stack *stack, int value) {
	if(stack == NULL) {
		printf("stack is null");
		exit(1);
	}

	Node *newNode = (Node *)malloc(sizeof(Node));
	if(newNode == NULL) {
		printf("Allocation for newNode failed\n");
		exit(1);
	}

	newNode->next = stack->top;
	newNode->data = value;
	stack->top = newNode;
}

int pop(Stack *stack) {
	if(stack == NULL) {
		printf("stack is null");
		exit(1);
	}

	Node *top_node = stack->top;
	int value = top_node->data;
	stack->top = top_node->next;
	free(top_node);

	return value;
}

int peek(Stack *stack) {
	if(stack == NULL) {
		printf("stack is null");
		exit(1);
	}

	if(isEmpty(stack)) {
		printf("Stack is empty\n");
		exit(1);
	}

	return(stack->top->data);
}
