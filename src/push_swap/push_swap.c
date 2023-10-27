/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:08 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:45:29 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//manages the whole process of the push_swap program
int push_swap(Twix *twix) {
	Node *min;
	int steps;
	
	if(twix->a.length == 3)
		return (three_sort(twix));
	if(twix->a.length == 5)
		return (five_sort(twix));
	min = is_pseudo_sorted(&twix->a);
	if(min)
		return(balance(twix, min));
	steps = clean(twix);
	steps += inject_back(twix);
	min = is_pseudo_sorted(&twix->a);
	if(min)
		steps += balance(twix, min);

	return (steps);
}






