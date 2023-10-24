#include "../include/push_swap.h"

int search_for_insertion_location(Stack *stack, int val) {
	Node *this_node;
	Node *max_val_node;
	Node *min_val_node;
	int i;

	if(!stack)
		return (-1); //stack is null
	if(is_empty(stack))
		return (0);

	i = 0;
	max_val_node = stack->top;
	min_val_node = stack->top;
	this_node = stack->top;
	while(i++ < stack->length) {
		if(val < this_node->data && val > this_node->prev->data)
			return (this_node->pos);
		if(max_val_node->data > this_node->data)
			max_val_node = this_node;
		if(min_val_node->data < this_node->data)
			min_val_node = this_node;
		this_node = this_node->next;
	}
	return max_val_node->pos;
	//return 0;
}



/*	- Calculates 'scores' for each of the elements of the stack_b and stores them 
	in the array under an indeces, which corresponds to the position of an element 
	in the stack, e.g. the 'score' of the n-th element of the stack will be saved
	in the array under the index 'n'.
	- Stack 'a' accepts element from 'b'
	- Scores are calculated considering six cases: see description of stacks_rotation_options()
	- Each of the above cases also may assumes zero movement */

//int *calculate_scores(Stack *stack_a, Stack *stack_b) {
	//int len;
	//int ins_loc; //insertion location in the stack 'a'
	//Node *this_node;

	//len = 0;
	//this_node = stack_b->top;
	//while(len < stack_b->length) {
		//ins_loc = search_for_insertion_location(stack_a, this_node->data);
		//calculate_score(ins_loc, this_node->pos, stack_a->length, stack_b->length);
	//}

//}

/*	- This function calculates and returns the 'score' (which is the minimal 
	number of 'steps' that needs to be done in order to place an alement that
	'seats' at the location 'loc_b' in stack_b into a location loc_a of the stack 'a')
	- loc_a is the location in stack 'a' where a value needs to be placed
	- loc_b is the location of the value in stack_b that needs to be placed into stack_a
	- len_a is the length of the stack_a
	- len_b is the length of the stack _b
*/
//int calculate_score(int loc_a, int loc_b, int len_a, int len_b) {

//}

int push_swap(Twix *twix) {
	int *rotations;
	int sum;

	sum = 0;
	sum += clean(twix);


	//while(twix->a.length > 0) {
		//pb(twix);
		//sum++;
	//}
	
	while(twix->b.length > 0) {
		//loc = search_for_insertion_location(&twix->a, twix->b.top->data);
		//rotations = rotation_options(loc, 0, twix->a.length, twix->b.length);
		rotations = cheapest_push(&twix->a, &twix->b);
		sum += ps_push(twix, rotations);
	}

	return (sum);
}


int clean(Twix *twix) {
	Int_array *lis_a; // 'lis' in stack 'a'
	int sum;
	int i;

	sum = 0;
	i = 0;
	lis_a = lis(&twix->a);
	while(i < lis_a->length) {
		if(twix->a.top->data != lis_a->array[i]) {
			pb(twix);
			sum++;
		} else {
			ra(twix);
			sum++;
			i++;
			continue;
		}
		if(twix->a.top->next == twix->a.top)
			break;
	}
	return sum;
}
 
int *cheapest_push(Stack *stack_a, Stack *stack_b) {
	int i;
	int loc;
	int min_ops;
	Node *this_node;
	Node *cheap_node;
	int *rotations;

	i = 0;
	this_node = stack_b->top;
	cheap_node = stack_b->top;
	min_ops = INT_MAX;

	while(++i < stack_b->length) {
		loc = search_for_insertion_location(stack_a, this_node->data);
		rotations = rotation_options(loc, this_node->pos, stack_a->length, stack_b->length);
		if(sumup_rotations(rotations) < min_ops) {
			min_ops = sumup_rotations(rotations);
			cheap_node = this_node;
		}
		this_node = this_node->next;
	}
	loc = search_for_insertion_location(stack_a, cheap_node->data);
	rotations = rotation_options(loc, cheap_node->pos, stack_a->length, stack_b->length);
	return rotations;
}

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

int ps_push(Twix *twix, int *steps) {
	int i;
	int j;
	int sum; //keeps number of operations performed

	int (*operation[])(Twix *) = {rr, rrr, ra, rra, rb, rrb};

	i = 0;
	sum = 0;
	while(i < STEPS) {
		j = 0;
		while(j < steps[i])	{
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
