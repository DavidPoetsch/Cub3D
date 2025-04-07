/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 07:26:00 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief The strlcat() function appends the NUL-terminated
 *				string src to the end of dst.  It will append at most
 *				size - strlen(dst) - 1 bytes, NUL-terminating the result.
 * @param dst	Destination string.
 * @param src	Source string.
 * @param size	Size of the destination string.
 * @return size_t	The strlcat() functions returns the to‐
 *								tal length of the string it tried to create. For
 *								strlcat() that means the initial length of
 *								dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	icopy;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (src_len + size);
	icopy = 0;
	while ((dest_len + icopy) < (size - 1) && src[icopy] != '\0')
	{
		dst[dest_len + icopy] = src[icopy];
		icopy++;
	}
	if ((dest_len + icopy) < size)
	{
		dst[dest_len + icopy] = '\0';
		icopy++;
	}
	return (dest_len + src_len);
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	*src = "Hello";
	int size = 4;
	int buff = 5;
	char dest1[buff];
	char dest2[buff];
	ft_bzero(dest1, buff);
	ft_bzero(dest2, buff);

	printf("%zu\n", strlcat(dest1, src, size));
	printf("%s\n", dest1);
	printf("%zu\n", ft_strlcat(dest2, src, size));
	printf("%s\n", dest2);
} */
