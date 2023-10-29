/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:52:14 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/28 20:52:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_Twix	twix;

	init_twix(&twix);
	parsing(argc, argv, &twix.a);
	//printf("stack A\n");
	//print_stack(&twix.a);
	push_swap(&twix);
	//printf("steps after push_swap: %d\n", steps);
	//printf("PUSH_SWAP()\n");
	//printf("stack A\n");
	//print_stack(&twix.a);

//TESTING BLOCK START
	//t_Int_array	*lis_a = lis(&twix.a);
	//printf("lis_len: %d\n", lis_a->length);
	//for(int i = 0; i < lis_a->length; i++)
		//printf("lis[%d]: %d\n", i, lis_a->array[i]);
	//clean_foo(&twix, lis_a);	
	//while (twix.a.length > lis_a->length)
		//pb(&twix);
	//printf("After cleaning\n");
	//printf("Stack A\n");
	//print_stack(&twix.a);
	//printf("Stack B\n");
	//print_stack(&twix.b);
	//inject_back(&twix);
	//printf("After injection\n");
	//printf("Stack A\n");
	//print_stack(&twix.a);
	//t_Node *min = is_pseudo_sorted(&twix.a);
	//if (min)
		//balance(&twix, min);
	//printf("After Balance\n");
	//printf("Stack A\n");
	//print_stack(&twix.a);
//TESTING BLOCK END
	return (0);
}
