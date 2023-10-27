/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:28:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
 

