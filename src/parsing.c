#include "../include/push_swap.h"

void parsing(int argc, char **argv, Stack *a) {
	char **arg;
	int i;

	if(!a) {
		fprintf(stderr, "Error - parsing(): stack is NULL\n");
		exit(0);
	}

	if (argc < 2) {
		fprintf(stderr, "Error - parsing(): not enough argumetns");
		exit(1);
	}

	i = argc - 1;

	while (i > 0) {
		arg = ft_split(argv[i--], ' ');
		if(!*arg) {
			fprintf(stderr, "Error - parsing(): input is empty\n");
			exit(0);
		}
			
		check_and_push(arg, a);
	}
}

void check_and_push(char **str, Stack *stack) {
	int push_candidate_number;
	char **this_elem;

	this_elem = --str;
	while(*++this_elem);
	while (--this_elem != str) {
		push_candidate_number = ft_atoi(*this_elem);
		if (ft_strlen(ft_itoa(push_candidate_number)) != my_strlen(*this_elem)) {
			printf("Error - check_and_push(): is not a valid input: '%s'\n", *this_elem);
			exit(1);
		}
		if(!is_duplicate(stack, push_candidate_number)) {
			push(stack, push_candidate_number);
		} else
			exit(0);
	}
}

int is_duplicate(Stack *stack, int a) {
	Node *current_node;

	if(!stack){
		printf("Error - is_there_duplicates(): stack is NULL\n");
		exit(0);
	}

	if(!stack->top)
		return (0);
	if(stack->top->data == a) {
		printf("Error - is_there_duplicate(): there is a duplicate: %d\n", a);
		return (1);
	}
		
	current_node = stack->top;
	while(current_node->next != stack->top) {
		if(current_node->next->data == a) {
			printf("Error - is_there_duplicate(): there is a duplicate: %d\n", a);
			return (1);
		}
		current_node = current_node->next;
	}
	return (0);
}
 


