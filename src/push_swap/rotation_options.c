/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:45:20 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:45:23 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*	- This function returns an array of size 6, that contains number of steps
	that each of the stacks needs to be rotated in order to perform placement 
	of the element from stack_b to stack_a
	- index '0' indicates number of times both stacks to be rotated forward 'rr'
	- index '1' indicates number of times both stacks to be rotated backward 'rrr'
	- index '2' indicates number of times stack_a to be rotated forward 'ra' 
	- index '3' indicates number of times stack_a to be rotated backward 'rra' 
	- index '4' indicates number of times stack_b to be rotated forward 'rb' 
	- index '5' indicates number of times stack_b to be rotated backward 'rrb' 
	*/
int	*rot_ops(int loc_a, int loc_b, int len_a, int len_b)
{
	int	*rotations;

	rotations = (int *)ft_calloc(6, sizeof(int));
	if (loc_a <= len_a - loc_a + 1)
		rotations[2] = loc_a;
	else
		rotations[3] = len_a - loc_a;
	if (loc_b <= len_b - loc_b + 1)
		rotations[4] = loc_b;
	else
		rotations[5] = len_b - loc_b;
	if (rotations[2] > 0 && rotations[4] > 0)
	{
		rotations[0] = min(rotations[2], rotations[4]);
		rotations[2] -= rotations[0];
		rotations[4] -= rotations[0];
	}
	if (rotations[3] > 0 && rotations[5] > 0)
	{
		rotations[1] = min(rotations[3], rotations[5]);
		rotations[3] -= rotations[1];
		rotations[5] -= rotations[1];
	}
	return (rotations);
}
