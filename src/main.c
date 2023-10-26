#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	int steps;
	Twix twix;
	init_twix(&twix);
	 
	parsing(argc, argv, &twix.a);
	printf("stack A\n");
	print_stack(&twix.a);

	steps = push_swap(&twix);
	printf("steps after push_swap: %d\n", steps);
	printf("PUSH_SWAP()\n");
	printf("stack A\n");
	print_stack(&twix.a);
	printf("steps: %d\n", steps);

	return (0);
}


