#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	int sum;
	Twix twix;
	init_twix(&twix);
	 
	parsing(argc, argv, &twix.a);
	printf("stack A\n");
	print_stack(&twix.a);

	sum = balance(&twix);
	printf("sum = %d\n", sum);
	//printf("CLEAN()\n");
	//sum = clean(&twix);

	//sum = push_swap(&twix);
	//printf("steps after push_swap: %d\n", sum);
	//printf("PUSH_SWAP()\n");
	printf("stack A\n");
	print_stack(&twix.a);
	//sum += balance(&twix);

	//printf("FINAL OUTPUT\n");
	//printf("stack A\n");
	//print_stack(&twix.a);
	//printf("steps: %d\n", sum);

	return (0);
}


