#include "../include/push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int sa(Twix *twix) {
	int temp;

	if(!twix) {
		fprintf(stderr, "Error - sa(): twix is NULL");
		return (1);
	}

	if(!is_empty(&twix->a) && twix->a.top->next) {
		temp = peek(&twix->a);
		twix->a.top->data = twix->a.top->next->data;
		twix->a.top->next->data = temp;
	} else
		fprintf(stderr, "Error - sa(): stack is empty or there is only one node\n");
	
	printf("sa() is done\n");

	return (0);
}