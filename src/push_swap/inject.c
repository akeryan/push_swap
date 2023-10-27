#include "../../include/push_swap.h"

/*	- This function injects elements from stack 'b' to stack 'a' in there correct locatoins
	- Assumption is that stack 'a' is sorted (in an ascending order)
*/

void inject_back(Twix *twix) {
	int *rotations;

	while(twix->b.length > 0) {
		rotations = cheapest_push(&twix->a, &twix->b);
		ps_push(twix, rotations);
	}
}