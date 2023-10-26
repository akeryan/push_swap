/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:09:01 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/07 12:12:55 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	char	*hay;

	i = 0;
	nlen = ft_strlen(needle);
	hay = (char *)haystack;
	if (*needle == 0)
		return (hay);
	while (hay[i] && (i + nlen) <= len)
	{
		if (hay[i] == *needle)
			if (ft_strncmp(&hay[i], needle, ft_strlen(needle)) == 0)
				return (&hay[i]);
		i++;
	}
	return (NULL);
}
