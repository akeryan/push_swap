/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:52:45 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/23 14:01:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	ch = c;
	unsigned char		*str;

	str = (unsigned char *)s;
	while (n-- != 0)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
