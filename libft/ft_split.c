/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:00:25 by akeryan           #+#    #+#             */
/*   Updated: 2023/10/26 07:37:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	count_words(char const *str, char c)
{
	if (c == 0)
		return (1);
	while (*str == c)
		str++;
	if (*str == '\0')
		return (0);
	while (*str && *str != c)
		str++;
	return (1 + count_words(str, c));
}

int	word_len(char const *str, char c, int isWord)
{
	while (*str == c && isWord == 0)
		str++;
	if (*str == '\0' || *str == c)
		return (0);
	return (1 + word_len(++str, c, 1));
}

char	**foo(char **out, unsigned int pos, char const *str, char c)
{
	int	i;

	if (out == NULL || str == NULL || *str == '\0')
		return (out);
	while (*str == c)
		str++;
	if (*str == '\0')
		return (out);
	out[pos] = (char *)malloc(word_len(str, c, 0) + 1);
	if (out[pos] == NULL)
	{
		free_all(out);
		return (out);
	}
	i = 0;
	while (*str && *str != c)
		out[pos][i++] = *str++;
	out[pos][i] = '\0';
	return (foo(out, ++pos, str, c));
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int len;

	if (s == NULL)
		return (NULL);
	len = count_words(s, c) + 1;
	out = (char **)malloc(sizeof(char *) * len);
	if (out == NULL)
		return (NULL);
	out[len - 1] = NULL;
	out = foo(out, 0, s, c);
	return (out);
}
