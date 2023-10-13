/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:19:14 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/23 20:21:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*tostr(int n, int len, int sign)
{
	char	*p;
	int		num;

	p = (char *)malloc(len * sizeof(char) + 1);
	if (p == 0)
		return (NULL);
	p[len] = '\0';
	while (len != 0)
	{
		num = n % 10;
		p[--len] = num + '0';
		n /= 10;
	}
	if (sign == -1)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int num)
{
	int				len;
	int				sign;
	int				n;
	char			*p;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	n = num;
	len = 0;
	sign = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
		sign = -1;
	}
	len += numlen(n);
	p = tostr(n, len, sign);
	return (p);
}
