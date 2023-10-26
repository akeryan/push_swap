/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:23:14 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/20 18:58:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char a)
{
	while (*set)
		if (*set++ == a)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int			a;
	int			len;
	int			z;
	char		*out;	

	if (!str)
		return (NULL);
	a = -1;
	z = 0;
	len = 0;
	while (check(set, str[++a]))
		;
	if (str[a])
	{
		z = ft_strlen(str);
		while (check(set, str[--z]))
			;
		len = z - a + 1;
	}
	else
		len = 0;
	out = ft_substr(str, a, len);
	return (out);
}
