
#include "../include/push_swap.h"
//rrb (reverse rotate b): Shift down all elements of stack a by 1. The last element becomes the first one.
int rrb(Twix *twix) {
	if(!twix)
		return (1);

	twix->b.top = twix->b.top->prev;
	printf("rrb()\n");
	return (0);	
}