#include "../include/push_swap.h"

//ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
int ra(Twix *twix) {
	if(!twix)
		return (1);

	twix->a.top = twix->a.top->next;
	update_positions(&twix->a);
	if(PRINT == 1)
		printf("ra()\n");
	return (0);	
}