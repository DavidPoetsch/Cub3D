/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:39:12 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The  memcpy()  function  copies n bytes from memory
 *				area src to memory area  dest.   The  memory  areas
 *				must not overlap.  Use memmove(3) if the
 *				memory areas do overlap.
 * @param dst	Destination memory.
 * @param src	Source memory.
 * @param n	Amount of bytes to copy.
 * @return void*	The memcpy() function returns a pointer to dest.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (dst == src)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>

int	main(void)
{
	char	*dest;
	char	src[20];

	dest = NULL;
	memcpy(dest, src, 10);
	return (0);
}
 */