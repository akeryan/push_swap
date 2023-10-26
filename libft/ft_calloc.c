/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:07:06 by akeryan           #+#    #+#             */
/*   Updated: 2021/11/07 15:37:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The calloc() function contiguously allocates enough space for count 
	objects that are size bytes of memory each and returns a pointer
	to the allocated memory. The allocated memory is filled with bytes 
	of value zero. */

void	*ft_calloc(size_t count, size_t size)
{
	size_t	sz;
	void	*ptr;	

	sz = count * size;
	ptr = (void *)malloc(sz);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, sz);
	return (ptr);
}
