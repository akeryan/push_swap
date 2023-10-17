#include "../include/push_swap.h"

//pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
int pb(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->a))
		push(&twix->b, pop(&twix->a));
	else {
		fprintf(stderr, "Error - pb: stack 'a' is empty\n");
		exit(1);
	}

	printf("pb() is done\n");

	return (0);
}