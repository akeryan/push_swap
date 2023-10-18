#include "../include/push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int sb(Twix *twix) {
	int temp1;
	int temp2;

	if(!twix) {
		fprintf(stderr, "Error - sb(): twix is NULL");
		exit(1);
	}

	temp1 = pop(&twix->b);
	temp2 = pop(&twix->b);
	push(&twix->b, temp1);
	push(&twix->b, temp2);
			
	printf("sb() is done\n");

	return (0);
}