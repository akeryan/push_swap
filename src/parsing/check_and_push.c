/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:27:01 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:27:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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