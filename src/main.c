#include "push_swap.h"

int main(int argc, char *argv[])
{
	Stack stack_a;
	initialize(&stack_a);
	if (!input_validation(argc, argv, &stack_a))
	{
		fprintf(stderr, "Error (main.c): input data error\n");
		return (1);
	}

	return (0);
}
