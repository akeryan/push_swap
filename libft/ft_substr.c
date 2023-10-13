/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:46:06 by akeryan           #+#    #+#             */
/*   Updated: 2021/12/28 13:52:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t length)
{
	char	*ptr;
	size_t	i;

	if (start >= ft_strlen(str))
		length = 0;
	else if (length > ft_strlen(&str[start]))
		length = ft_strlen(&str[start]);
	ptr = (char *)malloc(sizeof (*ptr) * length + 1);
	i = 0;
	while (i < length)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
