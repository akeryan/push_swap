#include "../include/push_swap.h"

//searches in 'stack' the correct position where to place 'val'
int search_for_insertion_location(Stack *stack, int val) {
	Node *this_node;
	Node *max_val_node;
	int i;

	if(!stack)
		return (-1); //stack is null
	if(is_empty(stack))
		return (0);

	i = 0;
	max_val_node = stack->top;
	this_node = stack->top;
	while(i++ < stack->length) {
		if(val < this_node->data && val > this_node->prev->data)
			return (this_node->pos);
		if(max_val_node->data > this_node->data)
			max_val_node = this_node;
		this_node = this_node->next;
	}
	return max_val_node->pos;
	//return 0;
}

//manages the whole process of the push_swap program
int push_swap(Twix *twix) {
	Node *min;
	int steps;
	
	if(twix->a.length == 3)
		return (three_sort(twix));
	if(twix->a.length == 5)
		return (five_sort(twix));

	min = is_pseudo_sorted(&twix->a);
	if(min)
		return(balance(twix, min));

	printf("CLEAN\n\n");
	steps = clean(twix);
	printf("Stack A\n");
	print_stack(&twix->a);
	printf("Stack B\n");
	print_stack(&twix->b);

	steps += inject_back(twix);

	min = is_pseudo_sorted(&twix->a);
	if(min)
		steps += balance(twix, min);

	return (steps);
}

/*	if the twix->a is not pseudo-sorted it can be passed to 'clean' function
	in order to keep only a subsequence that is sorted (in an ascending order)
	the rest of the elements are pushed to the stack 'b'
*/
int clean(Twix *twix) {
	Int_array *lis_a; // 'lis' in stack 'a'
	int sum;
	int i;

	sum = 0;
	i = 0;
	lis_a = lis(&twix->a);
	if(lis_a->length > 1) {
		while( i < lis_a->length) {
			if(twix->a.top->data != lis_a->array[i]) {
				pb(twix);
				sum++;
			} else {
				ra(twix);
				sum++;
				i++;
			}
		}
	}
	while(twix->a.length > lis_a->length) {
		pb(twix);
		sum++;
	}
	free(lis_a);
	return sum;
}

/*	searches for an element in stack 'b' that 'costs' the least to push to stack 'a'
	in terms of number of operations (e.g. ra, rr, ...)
*/
int *cheapest_push(Stack *stack_a, Stack *stack_b) {
	int loc;
	int min_ops;
	Node *this_node;
	Node *cheap_node;
	int *rotations;
	int steps_count;

	this_node = stack_b->top;
	cheap_node = stack_b->top;
	min_ops = INT_MAX;

	while(42) {
		loc = search_for_insertion_location(stack_a, this_node->data);
		rotations = rotation_options(loc, this_node->pos, stack_a->length, stack_b->length);
		steps_count = sumup_rotations(rotations); 
		if(steps_count < min_ops) {
			min_ops = steps_count; 
			cheap_node = this_node;
		}
		if(this_node->next == stack_b->top)
			break;
		this_node = this_node->next;
	}
	loc = search_for_insertion_location(stack_a, cheap_node->data);
	rotations = rotation_options(loc, cheap_node->pos, stack_a->length, stack_b->length);
	return rotations;
}

// just sums up all the values in an array pointed by 'rots'
int sumup_rotations(int *rots) {
	int i;
	int sum;

	i = 0;
	sum = 0;
	while(i < STEPS) {
		sum += rots[i];
		i++;
	}
	return (sum);
}

/*	Implements execution of operations (e.g. ra, rr, ...) in accordance with 
	the instruction listed in 'actions' array
*/

int ps_push(Twix *twix, int *actions) {
	int i;
	int j;
	int sum; //keeps number of operations performed

	int (*operation[])(Twix *) = {rr, rrr, ra, rra, rb, rrb};

	i = 0;
	sum = 0;
	while(i < STEPS) {
		j = 0;
		while(j < actions[i])	{
			operation[i](twix);
			j++;
		}
		sum += j;
		i++;
	}
	pa(twix);
	return (sum + 1);
}

/*	- This function returns an array of size 6, that contains number of steps
	that each of the stacks needs to be rotated in order to perform placement 
	of the element from stack_b to stack_a
	- value under index '0' indicates number of times both stacks to be rotated forward 'rr'
	- value under index '1' indicates number of times both stacks to be rotated backward 'rrr'
	- value under index '2' indicates number of times stack_a to be rotated forward 'ra' 
	- value under index '3' indicates number of times stack_a to be rotated backward 'rra' 
	- value under index '4' indicates number of times stack_b to be rotated forward 'rb' 
	- value under index '5' indicates number of times stack_b to be rotated backward 'rrb' 
	*/
int *rotation_options(int loc_a, int loc_b, int len_a, int len_b) {
	int *rotations = (int *)ft_calloc(6, sizeof(int)); //dynamically allocated array of length 6

	if(loc_a <= len_a - loc_a + 1)
		rotations[2] = loc_a;
	else
		rotations[3] = len_a - loc_a;
	
	if(loc_b <= len_b - loc_b + 1)
		rotations[4] = loc_b;
	else
		rotations[5] = len_b - loc_b;

	if(rotations[2] > 0 && rotations[4] > 0) {
		rotations[0] = min(rotations[2], rotations[4]);
		rotations[2] -= rotations[0];
		rotations[4] -= rotations[0];
	}
	
	if(rotations[3] > 0 && rotations[5] > 0) {
		rotations[1] = min(rotations[3], rotations[5]);
		rotations[3] -= rotations[1];
		rotations[5] -= rotations[1];
	}

	return (rotations);
}
