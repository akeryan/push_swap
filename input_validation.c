
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "input_validation.h"

bool input_validation(int argc, char **argv, Stack *stack_a)
{
	if (!enough_arguments(argc))
		return false;

	while (*++argv != NULL)
	{
		printf("%s\n", *argv);
	}

	return (1);
}

bool enough_arguments(int argc)
{
	if (argc < 2)
	{
		fprintf(stderr, "Error (input_validatoin.c): Insufficient arguments.\n");
		return false;
	}
	else
		return true;
}