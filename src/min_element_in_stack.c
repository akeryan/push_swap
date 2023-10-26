#include "../include/push_swap.h"

// searches for and returns the minimal element of the 'stack'
Node *min_element_in_stack(Stack *stack) {
	Node *this;
	Node *min;

	if(!stack || !stack->top)
		return (NULL);
	
	this = stack->top;
	min = stack->top;
	while(42) {
		if(this->data < min->data)
			min = this;		
		if(this->next == stack->top)
			break;
		this = this->next;
	}
	return min;
}