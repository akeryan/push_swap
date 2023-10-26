#include "../include/push_swap.h"

/*	- checks whether 'stack' is pseudo-sorted
	- pseudo-sorted means that since 'stack' is a circular linked list, 
	it is sorted starting from some element of the stack
*/

Node *is_pseudo_sorted(Stack *stack) {
	Node *min;
	int result;

	min = min_element_in_stack(stack);
	result = is_sorted(min); 
	if(result == -1 || result == 0) 
		return (NULL);
	return (min);
}