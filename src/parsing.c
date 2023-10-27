/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:27:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// parses all the input values, meaning checks the validity of input values 
void parsing(int argc, char **argv, Stack *a) {
	char **arg;
	int i;

	if(!a) {
		fprintf(stderr, "Error - parsing(): stack is NULL\n");
		exit(0);
	}

	if (argc < 2) {
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

//checks each value of '**str' and if valid pushes to the 'stack'
void check_and_push(char **str, Stack *stack) {
	int push_candidate_number;
	int i = 0;
	while(str[i] != NULL)
		i++;
	while (42) {
		push_candidate_number = ft_atoi(str[--i]);
		if (ft_strlen(ft_itoa(push_candidate_number)) != my_strlen(str[i])) {
			printf("Error\n");
			exit(1);
		}
		if(!is_duplicate(stack, push_candidate_number)) {
			push(stack, push_candidate_number);
		} else
			exit(0);
		if(i == 0)
			break;
	}
}

//cheks whether value 'a' already present in 'stack'
int is_duplicate(Stack *stack, int a) {
	Node *current_node;

	if(!stack){
		printf("Error - is_duplicates(): stack is NULL\n");
		exit(0);
	}

	if(!stack->top)
		return (0);
		
	current_node = stack->top;
	while(42) {
		if(current_node->data == a) {
			printf("Error\n");
			return (1);
		}
		if(current_node->next == stack->top)
			break;
		current_node = current_node->next;
	}
	return (0);
}
 


