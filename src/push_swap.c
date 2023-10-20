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