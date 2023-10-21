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
	printf("stack A\n");
	print_stack(&twix.a);
	
	//printf("position: %d\n", search_for_insertion_location(&twix.a, 10));
	//int *rot = rotation_options(4, 12, 10, 14);
	//for(int i = 0; i < 6; i++)
		//printf("pos: %d, %d\n", i, rot[i]);
	return (0);
}


