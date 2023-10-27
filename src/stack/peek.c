/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:19:19 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:19:23 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// returns the value from the top of the 'stack' without popping it
int peek(Stack *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error - peek(): stack is null");
		exit(1);
	}

	if (is_empty(stack))
	{
		fprintf(stderr, "Error - peek(): Stack is empty\n");
		exit(1);
	}

	return (stack->top->data);
}