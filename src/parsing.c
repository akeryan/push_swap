
#include "../include/push_swap.h"

void parsing(int argc, char** argv, Stack* a) {
	char** arg;
	int i;

	if (argc < 2) {
		fprintf(stderr, "Error - parsing(): not enough argumetns");
		exit(1);
	}

	i = 1;

	while (i < argc) {
		arg = ft_split(argv[i++], ' ');
		check_and_push(arg, a);
	}
}

void check_and_push(char **str, Stack *stack) {
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
}

