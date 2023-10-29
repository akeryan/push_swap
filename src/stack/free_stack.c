/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:29:25 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/29 14:44:37 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_Stack *stack)
{
	t_Node	*this;

	this = stack->top;
	while (!this->prev)
	{
		free(this->next);
		this = this->prev;
	}
	free(this);
}
