#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	Twix twix;
	init_twix(&twix);
	
	if (!parsing(argc, argv, &twix.a))
	{
		fprintf(stderr, "Error (main.c): input data error\n");
		return (1);
	}
	printf("Stack A\n");
	print_stack(&twix.a);

//	pb(&twix);
	sa(&twix);

	printf("Stack A\n");
	print_stack(&twix.a);
	//printf("Stack B\n");
	//print_stack(&twix.b);
	return (0);
}
