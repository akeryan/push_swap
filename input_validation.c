
#include "push_swap.h"

int check_and_push(char **str, Stack *stack);

void print_split(char **spl);

bool input_validation(int argc, char **argv, Stack *stack_a)
{
	char **arg;
	int i;

	if (!enough_arguments(argc))
		return false;

	i = 1;

	while (i < argc)
	{
		arg = ft_split(argv[i++], ' ');
		// print_split(arg);
		check_and_push(arg, stack_a);
		printf("------------------\n");
	}

	printf("=====================\n");
	Node *node;
	node = stack_a->top;
	printf("%d\n", node->data);

	do
	{
		node = node->next;
		printf("%d\n", node->data);

	} while (node->next);

	return (1);
}

int check_and_push(char **str, Stack *stack)
{
	int push_candidate_number;

	while (*str != NULL)
	{
		push_candidate_number = atoi(*str);
		printf("%d\n", push_candidate_number);

		if (ft_strlen(ft_itoa(push_candidate_number)) != ft_strlen(*str))
		{
			printf("%s is not a valid number\n", *str);
			exit(1);
		}
		push(stack, push_candidate_number);
		str++;
	}
	return 1;
}

void print_split(char **spl)
{
	while (*spl != NULL)
	{
		printf("%s: %lu\n", *spl, ft_strlen(*spl));
		spl++;
	}
}

int ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);

	return (0);
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