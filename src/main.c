#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	Twix twix;
	init_twix(&twix);
	if(twix.a.top == NULL)
		printf("Stack a is initialized correctly\n");
	if(twix.b.top == NULL)
		printf("Stack b is initialized correctly\n");
	
	parsing(argc, argv, &twix.a);

	printf("Stack A\n");
	print_stack(&twix.a);
	printf("length: %d\n", stack_length(&twix.a));

	int p = pop(&twix.a);
	printf("poped value: %d\n", p);
	printf("Stack A\n");
	print_stack(&twix.a);

	

	//pb(&twix);
	//pb(&twix);
	//sa(&twix);
	//printf("Stack A\n");	
	//print_stack(&twix.a);
	//printf("Stack B\n");
	//print_stack(&twix.b);
	//printf("Stack B\n");
	//print_stack(&twix.b);
	return (0);
}
