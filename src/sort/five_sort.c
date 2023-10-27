/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:02:29 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:02:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// sorting algorithm for input of length 5
int five_sort(Twix *twix) {
	int steps;
	Node *pos;

	pb(twix);
	pb(twix);
	steps = three_sort(twix);
	steps += inject_back(twix);
	pos = is_pseudo_sorted(&twix->a);
	if(pos)
		steps += balance(twix, pos);
	return (steps);
}