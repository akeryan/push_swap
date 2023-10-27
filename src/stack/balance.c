/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:21:00 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:21:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// works correctly only if the stack is sorted in an ascending order
// 'foo' pointer shows the node from which the stack should be balanced and 
// can be identified with help of is_pseudo_sorted() function
int balance(Twix *twix, Node *foo) {
	int pos;
	int sum;

	if(foo == NULL)
		return (-1);
	pos = foo->pos;
	sum = 0;
	if(pos <= twix->a.length/2)
		while(pos-- > 0) {
			ra(twix);
			sum++;
		}
	else {
		pos = twix->a.length - pos;
		while(pos-- > 0) {
			rra(twix);
			sum++;
		}
	}
	return sum;
}