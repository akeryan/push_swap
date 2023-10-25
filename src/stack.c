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
		return;
	}

	Node *current_node;
	current_node = stack->top;
	printf("%d: %d\n", current_node->pos, current_node->data);
	while(current_node->next != stack->top) {
		current_node = current_node->next;
		printf("%d: %d\n", current_node->pos, current_node->data);
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

//int stack_length(Stack *stack) {
	//if (!stack) {
		//fprintf(stderr, "Error - stack_length(): stack is null");
		//exit(1);
	//}

	//return (stack->length);	
//}

void push(Stack *stack, int value)
{
	if (!stack) {
		fprintf(stderr, "Error - push(): stack is null");
		exit(1);
	}

	Node *new_node = malloc_node();
	new_node->data = value;
	new_node->pos = 0;

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
	update_positions(stack);
}

int pop(Stack *stack)
{
	int value;
	Node *temp;

	if (!stack)
	{
		fprintf(stderr, "Error - pop(): stack is null");
		exit(1);
	}

	if(is_empty(stack)) {
		printf("Error - pop(): Stack is empty\n");
		return (-1);
	}

	temp = stack->top;
	value = temp->data;
	if(stack->top->next == stack->top) { // it means that there is only one node, which is top node
		stack->top = NULL;
	} else {
		if (stack->top->next == stack->top->prev) { // it means that there are only two nodes
			stack->top->next->next = stack->top->next;
			stack->top->prev->prev = stack->top->prev;
		} else {
			temp = stack->top;
			stack->top->next->prev = stack->top->prev;
			stack->top->prev->next = stack->top->next;
		}
		stack->top = stack->top->next;					
	}
	stack->length--;
	update_positions(stack);

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

void update_positions(Stack *stack) {
	Node *this_node;
	int i;

	if(!stack || is_empty(stack))
		return;

	i = 0;
	stack->top->pos = i;
	this_node = stack->top->next;
	while(this_node != stack->top) {
		this_node->pos = ++i;
		this_node = this_node->next;
	}
}

// works correctly only if the stack is sorted in an ascending order
// 'foo' pointer shows the node from which the stack should be balanced
int balance(Twix *twix, Node *foo) {
	int pos;
	int sum;

	if(foo == NULL)
		return (-1);
	pos = foo->pos;
	sum = 0;
	if(pos < twix->a.length/2)
		while(pos-- >= 0) {
			ra(twix);
			sum++;
		}
	else {
		pos = twix->a.length - pos;
		while(pos-- > 0) {
			rra(twix);
			sum++;
		}
	}
	return sum;
}
