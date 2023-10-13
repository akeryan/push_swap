/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:33:06 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/04 14:50:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	strlcpy() copies up to n-1 characters from the string src to dest, 
	NUL-terminating the result if n is not 0. */

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	char		*to;
	const char	*from;

	to = dest;
	from = src;
	if (n != 0)
	{
		while ((*from != '\0') && (--n != 0))
			*to++ = *from++;
		*to = '\0';
	}
	return (ft_strlen(src));
}
