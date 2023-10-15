#include "../include/push_swap.h"

void init_stack(Stack *stack)
{
	if (!stack)
	{
		fprintf(stderr, "Error - init_stack(): stack is null");
		exit(1);
	}
	stack->top = NULL;
}

void print_stack(Stack *stack) {
	Node *current_node;

	current_node = stack->top;
	while(current_node != NULL) {
		printf("%d\n", current_node->data);
		current_node = current_node->next;
	}
}

bool is_empty(Stack *stack)
{
	if (!stack)
	{
		fprintf(stderr, "Error - is_empty(): stack is null");
		exit(1);
	}
	return (stack->top == NULL);
}

void push(Stack *stack, int value)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error - push(): stack is null");
		exit(1);
	}

	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error - push(): Allocation for new node failed\n");
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
		fprintf(stderr, "Error - pop(): stack is null");
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
		fprintf(stderr, "Error - peek(): stack is null");
		exit(1);
	}

	if (is_empty(stack))
	{
		fprintf(stderr, "Error - peek(): Stack is empty\n");
		exit(1);
	}

	return (stack->top->data);
}
