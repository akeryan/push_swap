/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:29:25 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 16:17:14 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_Stack *stack)
{
	t_Node	*tmp;
	t_Node	*buff;

	if (!stack || !stack->top)
		return ;
	tmp = NULL;
	while (tmp != stack->top)
	{
		if (!tmp)
			tmp = stack->top;
		buff = tmp;
		tmp = tmp->next;
		free(buff);
	}
	return ;
}
