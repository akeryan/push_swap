/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:58 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:14:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
int pb(Twix *twix) {
	if(!twix)
		return(1);

	if(!is_empty(&twix->a))
		push(&twix->b, pop(&twix->a));
	else {
		fprintf(stderr, "Error - pb: stack 'a' is empty\n");
		exit(1);
	}

	if(PRINT == 1)
		printf("pb\n");

	return (0);
}