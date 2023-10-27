/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:17:15 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 17:52:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// checks wheter 'stack' is empty or not
bool is_empty(Stack *stack)
{
	if (!stack)
		fprintf(stderr, "Error - is_empty(): stack is null");
	return (stack->top == NULL);
}