#include "../include/push_swap.h"

// sorting algorithm for input of length 3
int three_sort(Twix *twix) {
	Node *temp;
	int steps;

	temp = is_pseudo_sorted(&twix->a);
	if(temp != NULL)
		return (balance(twix, temp));
	sa(twix);
	steps = 1;
	steps += balance(twix, is_pseudo_sorted(&twix->a));
	return (steps);
}
