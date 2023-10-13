/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:39:33 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/06 09:13:06 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*to;
	const char	*from;
	size_t		orig_dst_len;
	size_t		empty_len;

	to = dst;
	from = src;
	orig_dst_len = ft_strlen(dst);
	if (dstsize != 0)
	{
		if (dstsize > orig_dst_len)
		{
			empty_len = dstsize - orig_dst_len;
			while (*to != '\0')
				to++;
			while ((*from != '\0') && (--empty_len != 0))
				*to++ = *from++;
			*to = '\0';
			return (orig_dst_len + ft_strlen(src));
		}
	}	
	return (dstsize + ft_strlen(src));
}
