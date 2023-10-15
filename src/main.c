#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	Twix twix;
	init_twix(&twix);
	if(twix.a.top == NULL)
		printf("Stack a is initialized correctly\n");
	if(twix.b.top == NULL)
		printf("Stack b is initialized correctly\n");
	
	if (!parsing(argc, argv, &twix.a))
	{
		fprintf(stderr, "Error (main.c): input data error\n");
		return (1);
	}
	printf("Stack A\n");
	print_stack(&twix.a);

	pb(&twix);
	pb(&twix);
	sa(&twix);

	printf("Stack A\n");
	print_stack(&twix.a);
	printf("Stack B\n");
	print_stack(&twix.b);
	//printf("Stack B\n");
	//print_stack(&twix.b);
	return (0);
}
