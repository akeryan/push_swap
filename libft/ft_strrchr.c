/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 09:21:04 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/14 19:58:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	ch = c;
	const char	*ptr = &s[ft_strlen(s)];

	while (*ptr != ch)
	{
		if (ptr == s)
			return (NULL);
		ptr--;
	}
	return ((char *)ptr);
}
