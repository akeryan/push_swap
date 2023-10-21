#include "../include/push_swap.h"

//rb (rotate b): Shift up all elements of stack a by 1. The first element becomes the last one.
int rb(Twix *twix) {
	if(!twix)
		return (1);

	twix->b.top = twix->b.top->next;
	printf("rb()\n");
	return (0);	
}