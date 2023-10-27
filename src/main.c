/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 21:05:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	Twix twix;

	init_twix(&twix);
	parsing(argc, argv, &twix.a);

	//printf("stack A\n");
	//print_stack(&twix.a);

	push_swap(&twix);
	//printf("steps after push_swap: %d\n", steps);
	//printf("PUSH_SWAP()\n");
	//printf("stack A\n");
	//print_stack(&twix.a);
	return (0);
}


