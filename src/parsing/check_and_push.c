/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:27:01 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/31 09:38:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//checks each value of '**str' and if valid pushes to the 'stack'
void	check_and_push(char **str, t_node *stack)
{
	int		push_candidate_number;
	char	*itoa_value;
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (42)
	{
		push_candidate_number = ft_atoi(str[--i]);
		itoa_value = ft_itoa(push_candidate_number);
		check_allocation(itoa_value);
		if (ft_strlen(itoa_value) != my_strlen(str[i]))
		{
			printf("Error\n");
			free(itoa_value);
			exit(1);
		}
		if (!is_duplicate(stack, push_candidate_number))
			push(stack, push_candidate_number);
		free(itoa_value);
		if (i == 0)
			break ;
	}
}
