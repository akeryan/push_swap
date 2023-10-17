#include "../include/push_swap.h"

//sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
int sb(Twix *twix) {
	int temp;

	if(!twix) {
		fprintf(stderr, "Error (sb(): twix is NULL");
		return (1);
	}

	if(!is_empty(&twix->b) && twix->b.top->next) {
		temp = peek(&twix->b);
		twix->b.top->data = twix->b.top->next->data;
		twix->b.top->next->data = temp;
	} else {
		fprintf(stderr, "Error - sb(): stack is empty or there is only one node");
		exit(1);
	}
	
	printf("sb() is done\n");

	return (0);
}