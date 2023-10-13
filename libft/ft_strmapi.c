/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:59:34 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/15 18:14:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	p = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (p == 0)
		return (NULL);
	i = -1;
	while (s[++i])
		p[i] = f(i, s[i]);
	p[i] = '\0';
	return (p);
}
