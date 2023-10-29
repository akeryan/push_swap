/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:15:26 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 15:01:56 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// initializes 't_Stack' structure
void	init_stack(t_Stack *stack)
{
	if (!stack)
	{
		fprintf(stderr, "Error - init_stack(): stack is null");
		exit(1);
	}
	stack->length = 0;
	stack->top = NULL;
}
