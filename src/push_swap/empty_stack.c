/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:55:59 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/02 10:28:51 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	empty_stack(t_twix *twix)
{
	int	len;

	len = twix->a.length;
	while (len > 2)
	{
		pb(twix);
		len--;
	}
}
