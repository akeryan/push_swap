/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:57 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 21:01:58 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// sorting algorithm for input of length 3
void three_sort(Twix *twix) {
	Node *temp;

	temp = is_pseudo_sorted(&twix->a);
	if(temp != NULL)
		return (balance(twix, temp));
	sa(twix);
	balance(twix, is_pseudo_sorted(&twix->a));
}
