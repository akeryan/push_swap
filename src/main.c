#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	int num_of_ops;
	Twix twix;
	init_twix(&twix);
	if(twix.a.top == NULL)
		printf("Stack a is initialized correctly\n");
	if(twix.b.top == NULL)
		printf("Stack b is initialized correctly\n");
	
	parsing(argc, argv, &twix.a);
	printf("stack A\n");
	print_stack(&twix.a);

	num_of_ops = push_swap(&twix);
	//PS_PUSH
	//pb(&twix);
	//pb(&twix);
	//pb(&twix);
	printf("stack A\n");
	print_stack(&twix.a);
	printf("stack B\n");
	print_stack(&twix.b);

	printf("Num of steps: %d\n", num_of_ops);

	//int *rotations = rotation_options(1, 1, 2, 3);
	//for (int i = 0; i < STEPS; i++) {
		//printf("pos %d: %d\n", i, rotations[i]);
	//}

	//ps_push(&twix, rotations);

	//printf("stack A\n");
	//print_stack(&twix.a);
	//printf("stack B\n");

	
	
	//printf("position: %d\n", search_for_insertion_location(&twix.a, 10));
	//search_for_insertion_location(&twix.a, 10);
	//int *rot = rotation_options(4, 12, 10, 14);
	//for(int i = 0; i < 6; i++)
		//printf("pos: %d, %d\n", i, rot[i]);
	//printf("loc: %d", search_for_insertion_location(&twix.a, 10));
	return (0);
}


