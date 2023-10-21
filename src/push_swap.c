#include "../include/push_swap.h"

int search_for_insertion_location(Stack *stack, int val) {
	Node *this_node;
	int i;

	if(!stack)
		return (-1); //stack is null
	if(is_empty(stack))
		return (0);

	i = 0;
	this_node = stack->top;
	while(i++ < stack->length) {
		if(val < this_node->data && val > this_node->prev->data)
			return (this_node->pos);
		this_node = this_node->next;
	}
	return (0);
}

/*	- Calculates 'scores' for each of the elements of the stack_b and stores them 
	in the array under an indeces, which corresponds to the position of an element 
	in the stack, e.g. the 'score' of the n-th element of the stack will be saved
	in the array under the index 'n'.
	- Stack 'a' accepts element from 'b'
	- Scores are calculated considering four cases:
		- simultaneous motion of both stacks forward 'rr': 1-st becoms last
		- simultaneous motion of both stacks backward 'rrr': last becomes first
		- 'a' moves forward ('ra'), while 'b' moves backward ('rrb') 
		- 'a' moves backward ('rra'), while 'b' moves forward ('rb')
	- Each of the above cases also may assumes zero movement
*/ 
//int *calculate_scores(Stack *a, Stack *b) {
	//int len;
	//Node this_node;

	//len = 0;
	//while(len < b->length) {

	//}

//}