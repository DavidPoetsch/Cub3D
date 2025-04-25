/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:39:12 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The memmove() function copies len bytes
 *				from string src to string dst.
 *				The two strings may overlap;
 *				The copy is always done in a non-destructive manner.
 * @param dst	Memory destination.
 * @param src	Memory source.
 * @param n	Bytes to move.
 * @return void*	Returns a pointer to dest
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (dst == src)
		return (dst);
	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	if (dst_ptr < src_ptr || dst_ptr >= (src_ptr + n))
	{
		while (i < n)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
		return (dst);
	}
	i = n;
	while (i > 0)
	{
		dst_ptr[i - 1] = src_ptr[i - 1];
		i--;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buffer1[20] = "Hello, World!";
// 	char	buffer2[20] = "Hello, World!";
// 	int		start1;
// 	int		start2;
// 	int		len;

// 	start1 = 7;
// 	start2 = 6;
// 	len = 6;
// 	// Overlapping copy (moving "World!" to the beginning of buffer)
// 	ft_memmove(buffer1 + start1, buffer1 + start2, len);
// 	memmove(buffer2 + start1, buffer2 + start2, len);
// 	// Print the result
// 	printf("Result: '%s'\n", buffer1);
// 	printf("Result: '%s'\n", buffer2);
// 	return (0);
// }
