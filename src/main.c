#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	Twix twix;
	init_twix(&twix);
	
	if (!parsing(argc, argv, &twix.stack_a))
	{
		fprintf(stderr, "Error (main.c): input data error\n");
		return (1);
	}
	printf("Stack A\n");
	print_stack(&twix.stack_a);

	pb(&twix);

	printf("Stack A\n");
	print_stack(&twix.stack_a);
	printf("Stack B\n");
	print_stack(&twix.stack_b);
	return (0);
}
