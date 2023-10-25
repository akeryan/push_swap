#include "../include/push_swap.h"

Node *is_pseudo_sorted(Stack *stack) {
	Node *this;

	if(!stack)
		return (NULL);

	this = stack->top;
	while(42) {
		if(is_sorted(this) == -1)
			return (NULL); //stack is empty
		if(is_sorted(this) == 1)
			 return this; //stack is pseudo_sorted; 'this' pointer is returned
		if(this->next == stack->top)
			break;
		this = this->next;
	}	
	return (NULL);
}