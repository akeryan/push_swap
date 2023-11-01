/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:27:01 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/01 11:49:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		ft_strcmp(const char *s1, const char *s2);
char	*num_to_str(const char *str);

//checks each value of '**str' and if valid pushes to the 'stack'
void	check_and_push(char **str, t_stack *stack)
{
	int		push_candidate_number;
	char	*itoa_value;
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (42)
	{
		push_candidate_number = ft_atoi(str[--i]);
		itoa_value = ft_itoa(push_candidate_number);
		check_allocation(itoa_value);
		if (ft_strcmp(itoa_value, num_to_str(str[i])))
		{
			printf("Error\n");
			free(itoa_value);
			exit(1);
		}
		if (!is_duplicate(stack, push_candidate_number))
			push(stack, push_candidate_number);
		free(itoa_value);
		if (i == 0)
			break ;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*num_to_str(const char *str)
{
	int	is_minus;

	is_minus = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_minus = 1;
		str++;
	}
	while (*str == '0')
	{
		if (ft_strlen(str) == 1)
			return (ft_itoa(0));
		str++;
	}
	if (!ft_isdigit(*str))
	{
		return (ft_strdup(str));
	}
	if (is_minus == 1)
		return (ft_strjoin("-", ft_strdup(str)));
	return (ft_strdup(str));
}
