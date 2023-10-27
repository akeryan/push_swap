/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:02:29 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 21:03:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// sorting algorithm for input of length 5
void five_sort(Twix *twix) {
	Node *pos;

	pb(twix);
	pb(twix);
	three_sort(twix);
	inject_back(twix);
	pos = is_pseudo_sorted(&twix->a);
	if(pos)
		balance(twix, pos);
}