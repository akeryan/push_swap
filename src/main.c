#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	int sum;
	Twix twix;
	init_twix(&twix);
	
	parsing(argc, argv, &twix.a);
	printf("stack A\n");
	print_stack(&twix.a);

	//printf("CLEAN()\n");
	//sum = clean(&twix);

	printf("PUSH_SWAP()\n");
	sum = push_swap(&twix);

	printf("FINAL OUTPUT\n");
	printf("stack A\n");
	print_stack(&twix.a);
	printf("steps: %d\n", sum);

	return (0);
}


