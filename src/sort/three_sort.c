/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:57 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:03:13 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// sorting algorithm for input of length 3
int three_sort(Twix *twix) {
	Node *temp;
	int steps;

	temp = is_pseudo_sorted(&twix->a);
	if(temp != NULL)
		return (balance(twix, temp));
	sa(twix);
	steps = 1;
	steps += balance(twix, is_pseudo_sorted(&twix->a));
	return (steps);
}
