/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:55:26 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The strlcpy() function copies up to size - 1 characters
 *				from the NUL-terminated string src to dst,
 *				NUL-terminating the result.
 * @param dst	Destination string.
 * @param src	Source string.
 * @param size	Size of the destination string.
 * @return size_t	The strlcpy() function returns the total
 *								length of the string they tried to create.
 *								For strlcpy() that means the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/* #include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	*src;
	int		size;
	int		buff;
	char	dest1[buff];
	char	dest2[buff];

	src = "Hello";
	size = 8;
	buff = 5;
	ft_bzero(dest1, buff);
	ft_bzero(dest2, buff);
	printf("%zu\n", strlcpy(dest1, src, size));
	printf("%s\n", dest1);
	printf("%zu\n", ft_strlcpy(dest2, src, size));
	printf("%s\n", dest2);
} */
