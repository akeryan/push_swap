#include "../include/push_swap.h"
//rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
int rra(Twix *twix) {
	if(!twix)
		return (1);

	twix->a.top = twix->a.top->prev;
	return (0);	
}