/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:28 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 09:54:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
int sb(Twix *twix) {
	int temp1;
	int temp2;

	if(!twix) {
		fprintf(stderr, "Error - sb(): twix is NULL");
		exit(1);
	}

	temp1 = pop(&twix->b);
	temp2 = pop(&twix->b);
	push(&twix->b, temp1);
	push(&twix->b, temp2);
			
	if(PRINT == 1)
		printf("sb()\n");

	return (0);
}