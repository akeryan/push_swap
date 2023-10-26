/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:10:52 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/22 18:13:50 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*p;
	int		num;
	int		sign;

	p = (char *)str;
	num = 0;
	sign = 1;
	while (*p == 32 || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			sign *= -1;
		p++;
	}
	while (ft_isdigit(*p))
	{
		num *= 10;
		num += (*p - '0');
		p++;
	}
	return (num * sign);
}
