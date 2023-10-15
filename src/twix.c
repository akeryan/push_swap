#include "../include/push_swap.h"

void init_twix(Twix *twix) {
	if(!twix) {
		fprintf(stderr, "Error (twix.c): twix is NULL\n");
		exit(1);
	}
	init_stack(&twix->a);
	init_stack(&twix->b);
}

//sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int sa(Twix *twix) {
	int temp;

	if(!twix) {
		fprintf(stderr, "Error - sa(): twix is NULL");
		return (1);
	}

	if(!is_empty(&twix->a) || twix->a.top->next) {
		temp = peek(&twix->a);
		twix->a.top->data = twix->a.top->next->data;
		twix->a.top->next->data = temp;
	} else
		fprintf(stderr, "Error - sa(): stack is empty or there is only one node");
	
	printf("sa() is done\n");

	return (0);
}

//sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
int sb(Twix *twix) {
	int temp;

	if(!twix) {
		fprintf(stderr, "Error (sb(): twix is NULL");
		return (1);
	}

	if(!is_empty(&twix->b) || twix->b.top->next) {
		temp = peek(&twix->b);
		twix->b.top->data = twix->b.top->next->data;
		twix->b.top->next->data = temp;
	} else 
		fprintf(stderr, "Error - sb(): stack is empty or there is only one node");
	
	printf("sb() is done\n");

	return (0);
}

//ss : sa and sb at the same time.
int ss(Twix *twix) {
	sa(twix);
	sb(twix);
	printf("ss() is done\n");

	return (0);
}
//pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
int pa(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->b))
		push(&twix->a, pop(&twix->b));
	
	printf("pa() is done\n");

	return (0);
}

//pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
int pb(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->a))
		push(&twix->b, pop(&twix->a));

	printf("pb() is done\n");

	return (0);
}