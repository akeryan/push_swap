#include "push_swap.h"

void initialize(Stack *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error (stack.c):stack is null");
		exit(1);
	}
	stack->top = NULL;
}

bool isEmpty(Stack *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error (stack.c): stack is null");
		exit(1);
	}
	return (stack->top == NULL);
}

void push(Stack *stack, int value)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error (stack.c): stack is null");
		exit(1);
	}

	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error (stack.c): Allocation for newNode failed\n");
		exit(1);
	}

	newNode->next = stack->top;
	newNode->data = value;
	stack->top = newNode;
}

int pop(Stack *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error (stack.c): stack is null");
		exit(1);
	}

	Node *top_node = stack->top;
	int value = top_node->data;
	stack->top = top_node->next;
	free(top_node);

	return value;
}

int peek(Stack *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error (stack.c): stack is null");
		exit(1);
	}

	if (isEmpty(stack))
	{
		fprintf(stderr, "Error (stack.c): Stack is empty\n");
		exit(1);
	}

	return (stack->top->data);
}
