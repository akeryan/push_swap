/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:29:25 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 08:34:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*buff;

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
