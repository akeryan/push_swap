/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:38 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 10:25:00 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//rr : ra and rb at the same time.
int rr(Twix *twix) {
	ra(twix);
	rb(twix);

	if(PRINT == 1)
		printf("rr\n");

	return (0);
}