/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:39 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:23:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
int pa(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->b))
		push(&twix->a, pop(&twix->b));
	else {
		fprintf(stderr, "Error - pb: stack 'b' is empty\n");
		exit(1);
	}
	if(PRINT == 1)
		printf("pa\n");

	return (0);
}