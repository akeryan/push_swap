/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sumup_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:43:55 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/27 20:11:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// just sums up all the values in an array pointed by 'rots'
int sumup_array(int *rots, int len) {
	int i;
	int sum;

	i = 0;
	sum = 0;
	while(i < len) {
		sum += rots[i];
		i++;
	}
	return (sum);
}