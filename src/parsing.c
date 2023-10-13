
#include "../include/push_swap.h"

bool parsing(int argc, char** argv, Stack* stack_a) {
	char** arg;
	int i;

	if (!enough_arguments(argc))
		return false;

	i = 1;

	while (i < argc) {
		arg = ft_split(argv[i++], ' ');
		check_and_push(arg, stack_a);
	}

	printf("\nStack:\n");
	print_stack(stack_a);

	return (1);
}

int check_and_push(char **str, Stack *stack) {
	int push_candidate_number;

	while (*str != NULL) {
		push_candidate_number = ft_atoi(*str);
		printf("%d\n", push_candidate_number);
		
		if (ft_strlen(ft_itoa(push_candidate_number)) != my_strlen(*str)) {
			printf("%s is not a valid number\n", *str);
			exit(1);
		}
		push(stack, push_candidate_number);
		str++;
	}
	return 1;
}

bool enough_arguments(int argc) {
	if (argc < 2)
	{
		fprintf(stderr, "Error (input_validatoin.c): Insufficient arguments.\n");
		return false;
	}
	else
		return true;
}