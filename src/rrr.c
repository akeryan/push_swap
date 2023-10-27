/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:54:00 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 09:54:02 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

//rrr : rra and rrb at the same time.
int rrr(Twix *twix) {
	rra(twix);
	rrb(twix);

	if(PRINT == 1)
		printf("rrr()\n");

	return (0);
}