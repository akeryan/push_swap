#include "../include/push_swap.h"

// sorting algorithm for input of length 5
int five_sort(Twix *twix) {
	int steps;
	Node *pos;

	pb(twix);
	pb(twix);
	steps = three_sort(twix);
	steps += inject_back(twix);
	pos = is_pseudo_sorted(&twix->a);
	if(pos)
		steps += balance(twix, pos);
	return (steps);
}