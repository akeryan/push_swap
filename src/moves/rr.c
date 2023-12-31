/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:53:38 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 19:22:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//rr : ra and rb at the same time.
void	rr(t_twix *twix)
{
	twix->a.top = twix->a.top->next;
	update_positions(&twix->a);
	twix->b.top = twix->b.top->next;
	update_positions(&twix->b);
	printf("rr\n");
}
