/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:19:19 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 14:57:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// returns the value from the top of the 'stack' without popping it
int	peek(t_Stack *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error - peek(): stack is null");
		exit(1);
	}
	if (is_empty(stack))
	{
		fprintf(stderr, "Error - peek(): t_Stack is empty\n");
		exit(1);
	}
	return (stack->top->data);
}
