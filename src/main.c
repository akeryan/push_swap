#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	//int sum;
	Twix twix;
	init_twix(&twix);
	 
	parsing(argc, argv, &twix.a);
	printf("stack A\n");
	print_stack(&twix.a);

	Node *a = min_element_in_stack(&twix.a);
	//Node *a = is_pseudo_sorted(&twix.a);

	if(a != NULL)
		printf("Min element: %d\nPos: %d\n", a->data, a->pos);
	else
		printf("PSEUDO SORTED\n");
	//printf("CLEAN()\n");
	//sum = clean(&twix);

	//sum = push_swap(&twix);
	//printf("steps after push_swap: %d\n", sum);
	//printf("PUSH_SWAP()\n");
	//printf("stack A\n");
	//print_stack(&twix.a);
	//sum += balance(&twix);

	//printf("FINAL OUTPUT\n");
	//printf("stack A\n");
	//print_stack(&twix.a);
	//printf("steps: %d\n", sum);

	return (0);
}


