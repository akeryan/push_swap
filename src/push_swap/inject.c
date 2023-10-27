#include "../../include/push_swap.h"

/*	- This function injects elements from stack 'b' to stack 'a' in there correct locatoins
	- Assumption is that stack 'a' is sorted (in an ascending order)
*/

int inject_back(Twix *twix) {
	int *rotations;
	int steps;

	steps = 0;
	while(twix->b.length > 0) {
		rotations = cheapest_push(&twix->a, &twix->b);
		steps += ps_push(twix, rotations);
	}
	return (steps);
}