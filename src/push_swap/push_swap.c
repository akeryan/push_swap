/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:08 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 21:07:24 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//manages the whole process of the push_swap program
void push_swap(Twix *twix) {
	Node *min;
	
	if(twix->a.length == 3)
		three_sort(twix);
	if(twix->a.length == 5)
		five_sort(twix);
	min = is_pseudo_sorted(&twix->a);
	if(min)
		balance(twix, min);
	clean(twix);
	inject_back(twix);
	min = is_pseudo_sorted(&twix->a);
	if(min)
		balance(twix, min);
}






