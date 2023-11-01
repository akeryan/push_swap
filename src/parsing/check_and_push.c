/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:27:01 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/01 22:13:06 by akeryan          ###   ########.fr       */
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
	char	*num_str;
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (42)
	{
		push_candidate_number = ft_atoi(str[--i]);
		itoa_value = ft_itoa(push_candidate_number);
		check_allocation(itoa_value);
		num_str = num_to_str(str[i]);
		if (ft_strcmp(itoa_value, num_str) != 0)
		{
			printf("Error\n");
			free(itoa_value);
			free(num_str);
			exit(1);
		}
		if (!is_duplicate(stack, push_candidate_number))
			push(stack, push_candidate_number);
		free(itoa_value);
		free(num_str);
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
	int		is_minus;
	char	*substr;

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
	substr = ft_strdup(str);
	if (!ft_isdigit(*str))
		return (substr);
	if (is_minus == 1)
	{ char *newstr = ft_strjoin("-", substr);
		free(substr);
		return (newstr);
	}
	return (substr);
}
