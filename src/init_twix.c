#include "../include/push_swap.h"

void init_twix(Twix *twix) {
	if(!twix) {
		fprintf(stderr, "Error (twix.c): twix is NULL\n");
		exit(1);
	}
	init_stack(&twix->a);
	init_stack(&twix->b);
}