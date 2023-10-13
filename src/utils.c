#include <stdio.h>
#include <stddef.h>
#include "libft.h"

/* atoi_strlen() returns the length of the initial part of the string that is to be converted to int representation
 * first skips all the white spaces,
 * then skips '+' or '-' if present; 
 * in case if '-' it counts for part of string length;
 * '+' is valid but doesn't contribute to the lenght
 * then skips all the '0' if present (e.g. '-0004' is valid and equal to '-4');
 * then measure length of the remaining string with ft_strlen();
*/

size_t	my_strlen(const char *str)
{
	size_t	len;

	len = 0;

	//skip all the white spaces
	while (*str== 32 || (*str>= 9 && *str <= 13))
		str++;

	if (*str == '+' || *str == '-') {
		if(*str == '-')
			len++;
		str++;
	}

	while(*str == '0')
		str++;
	
	if(!ft_isdigit(*str))
		len--;

	len += ft_strlen(str);

	return (len);
}