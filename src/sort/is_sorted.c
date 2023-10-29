/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:02:48 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 19:49:09 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- Checks whether the circular stack is pseudo-sorted or not
	- if 'start' is the top of the stack then it checks whether it is sorted
	- pseudo-sorted refers to the situation, when the stack is sorted starting 
	from some element of the stack (since the stack is circular, it means that 
	it is sorted starting from that element and not starting from the top)
*/
int	is_sorted(t_Node *start)
{
	t_Node	*this;

	if (!start)
		return (-1);
	if (start == start->next)
		return (1);
	this = start;
	while (42)
	{
		if (this->next == start)
			break ;
		if (this->data > this->next->data)
			return ((int)0);
		this = this->next;
	}
	return (1);
}
