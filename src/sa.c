#include "../include/push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int sa(Twix *twix) {
	int temp1;
	int temp2;

	if(!twix) {
		fprintf(stderr, "Error - sa(): twix is NULL");
		exit(1);
	}

	temp1 = pop(&twix->a);
	temp2 = pop(&twix->a);
	push(&twix->a, temp1);
	push(&twix->a, temp2);
			
	printf("sa()\n");

	return (0);
}