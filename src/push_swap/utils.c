/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:55:05 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/30 16:07:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* atoi_strlen() returns the length of the initial part of the string that 
	is to be converted to int representation
 * first skips all the white spaces,
 * then skips '+' or '-' if present; 
 * in case if '-' it counts for part of string length;
 * '+' is valid but doesn't contribute to the lenght
 * then skips all the '0' if present (e.g. '-0004' is valid and equal to '-4');
 * then measure length of the remaining string with ft_strlen();
*/

size_t	my_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			len++;
		str++;
	}
	while (*str == '0')
	{
		if (ft_strlen(str) == 1)
			return (1);
		str++;
	}
	if (!ft_isdigit(*str))
		len--;
	len += ft_strlen(str);
	return (len);
}

//	returns the minimal out of the two values
int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

//	returns the maximal out of the two values
int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// initializes the 'twix' structure
void	init_twix(t_Twix *twix)
{
	if (!twix)
	{
		fprintf(stderr, "Error (twix.c): twix is NULL\n");
		exit(1);
	}
	init_stack(&twix->a);
	init_stack(&twix->b);
}

//processes pointer that was assigned an allocated memory
void	check_allocation(void *ptr)
{
	if (!ptr)
	{
		printf("Error: failed to allocate memory\n");
		exit(1);
	}
}
