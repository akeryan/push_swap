/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 10:09:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_twix	twix;

	init_twix(&twix);
	parsing(argc, argv, &twix.a);
	//print_stack(&twix.a);
	push_swap(&twix);
	free_stack(&twix.a);
	return (0);
}
