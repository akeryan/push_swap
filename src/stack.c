#include "../include/push_swap.h"

void init_stack(Stack *stack)
{
	if (!stack)
	{
		fprintf(stderr, "Error - init_stack(): stack is null");
		exit(1);
	}
	stack->length = 0;
	stack->top = NULL;
}

Node *malloc_node() {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node) {
		fprintf(stderr, "Error - malloc_node(): Allocation for new node failed\n");
		exit(1);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = 0;
	return new_node;
}

void print_stack(Stack *stack) {
	if(!stack) {
		fprintf(stderr, "Error - pring_stack(): stack is NULL\n");
		exit(0);
	}
		
	if(is_empty(stack)) {
		fprintf(stderr, "Error - print_stack(): stack is empty\n");
		exit(0);
	}

	Node *current_node;
	current_node = stack->top;
	printf("%d\n", current_node->data);
	while(current_node->next != stack->top) {
		current_node = current_node->next;
		printf("%d\n", current_node->data);
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

int stack_length(Stack *stack) {
	if (!stack) {
		fprintf(stderr, "Error - stack_length(): stack is null");
		exit(1);
	}

	return (stack->length);	
}

void push(Stack *stack, int value)
{
	if (!stack) {
		fprintf(stderr, "Error - push(): stack is null");
		exit(1);
	}

	Node *new_node = malloc_node();
	new_node->data = value;

	if(!is_empty(stack)){
		new_node->next = stack->top;
		if(stack->top->next == stack->top) { // it means that there is only one node, which is top node
			new_node->prev = stack->top;
			stack->top->next = new_node;
			stack->top->prev = new_node;
		} else { // stack->length > 1
			new_node->prev = stack->top->prev;
			stack->top->prev->next = new_node;
			stack->top->prev = new_node;
		}
	} else { // stack is empty
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	stack->top = new_node;
	stack->length++;
}

int pop(Stack *stack)
{
	if (!stack)
	{
		fprintf(stderr, "Error - pop(): stack is null");
		exit(1);
	}


	return 9;
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
