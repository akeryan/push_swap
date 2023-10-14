#include "../include/push_swap.h"

void init_twix(Twix *twix) {
	if(!twix) {
		fprintf(stderr, "Error (twix.c): twix is NULL\n");
		exit(1);
	}
	init_stack(&twix->stack_a);
	init_stack(&twix->stack_b);
}

//sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int sa(Stack *a) {
	int temp;

	if(!a)
		return (1);

	if(!is_empty(a) || !(a->top->next)) {
		temp = peek(a);
		a->top->data = a->top->next->data;
		a->top->next->data = temp;
	}

	return (0);
}

//pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
int pa(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->stack_b))
		push(&twix->stack_a, pop(&twix->stack_b));

	return (0);
}

//pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
int pb(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->stack_a))
		push(&twix->stack_b, pop(&twix->stack_a));

	return (0);
}