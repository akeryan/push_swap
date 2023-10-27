/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:42:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:42:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	if the twix->a is not pseudo-sorted it can be passed to 'clean' function
	in order to keep only a subsequence that is sorted (in an ascending order)
	the rest of the elements are pushed to the stack 'b'
*/
int clean(Twix *twix) {
	Int_array *lis_a; // 'lis' in stack 'a'
	int sum;
	int i;

	sum = 0;
	i = 0;
	lis_a = lis(&twix->a);
	if(lis_a->length > 1) {
		while( i < lis_a->length) {
			if(twix->a.top->data != lis_a->array[i]) {
				pb(twix);
				sum++;
			} else {
				ra(twix);
				sum++;
				i++;
			}
		}
	}
	while(twix->a.length > lis_a->length) {
		pb(twix);
		sum++;
	}
	free(lis_a);
	return sum;
}