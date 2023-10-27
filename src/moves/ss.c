/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:34 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 11:10:40 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//ss : sa and sb at the same time.
int ss(Twix *twix) {
	sa(twix);
	sb(twix);

	if(PRINT == 1)
		printf("ss\n");

	return (0);
}