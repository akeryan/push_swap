#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	//int num_of_ops;
	Twix twix;
	init_twix(&twix);
	if(twix.a.top == NULL)
		printf("Stack a is initialized correctly\n");
	if(twix.b.top == NULL)
		printf("Stack b is initialized correctly\n");
	
	parsing(argc, argv, &twix.a);
	printf("stack A\n");
	print_stack(&twix.a);

	int sum = clean(&twix);
	printf("stack A\n");
	print_stack(&twix.a);
	printf("stack B\n");
	print_stack(&twix.b);
	printf("steps: %d\n", sum);

	return (0);
}


