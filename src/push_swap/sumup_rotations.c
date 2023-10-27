/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumup_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:43:55 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 12:43:57 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// just sums up all the values in an array pointed by 'rots'
int sumup_rotations(int *rots) {
	int i;
	int sum;

	i = 0;
	sum = 0;
	while(i < STEPS) {
		sum += rots[i];
		i++;
	}
	return (sum);
}