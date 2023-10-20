#include "../include/push_swap.h"

int search_for_insertion_location(Stack *stack, int val) {
	Node *this_node;

	if(!stack || is_empty(stack))
		return (-1); //stack is null or stack is empty

	this_node = stack->top;
	if(val < this_node->data && val > this_node->prev->data)
		return (0);
	this_node = this_node->next;
	while(this_node != stack->top) {
		if(val < this_node->data && val > this_node->prev->data)
			return (this_node->pos);
		this_node = this_node->next;
	}
	return (0);
}

/*	Calculates 'scores' for each of the elements of the stack_b and stores them 
	in the array under an indeces, which corresponds to the position of an element 
	in the stack, e.g. the 'score' of the n-th element of the stack will be saved
	in the array under the index 'n'.
*/ 
int *calculate_scores(Twix *twix) {

}