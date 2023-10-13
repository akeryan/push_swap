#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	Stack stack_a;
	initialize(&stack_a);
	if (!parsing(argc, argv, &stack_a))
	{
		fprintf(stderr, "Error (main.c): input data error\n");
		return (1);
	}

	return (0);
}
