/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 14:22:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_Twix	twix;

	init_twix(&twix);
	parsing(argc, argv, &twix.a);
	push_swap(&twix);
	free_stack(&twix.a);
	return (0);
}
