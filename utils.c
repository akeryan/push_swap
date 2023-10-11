#include <stdio.h>
#include <stddef.h>
#include "libft.h"

/* my_strlen() first skips all the white spaces,
 * then skips '+' or '-' if present; in case if '-' it counts for part of string length;
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

	printf("mylen is:%zu\n", len);
	return (len);
}