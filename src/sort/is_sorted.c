/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:02:48 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:02:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- Checks whether the circular stack is pseudo-sorted or not
	- if 'start' is the top of the stack then it checks whether it is sorted
	- pseudo-sorted refers to the situation, when the stack is sorted starting from some element of the stack
	(since the stack is circular, it means that it is sorted starting from that element and not starting from the top)
*/
int is_sorted(Node *start) {
	Node *this;

	if(!start)
		return (-1); //stack is empty
	
	if(start == start->next)
		return (1); //only one element, meaning it is sorted

	this = start;
	while(42) {
		if(this->next == start) 
			break;
		if(this->data > this->next->data)
			return (0); // stack is not sorted
		this = this->next;
	}
	return (1);
}