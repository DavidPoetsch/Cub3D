/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:49:57 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The  memcmp()  function  compares the first n bytes
					(each interpreted as unsigned char) of  the  memory
					areas s1 and s2.
 * @param s1	Memory area 1
 * @param s2	Memory area 2
 * @param n	Amount of bytes to compare
 * @return int	The memcmp() function returns zero if the two
 *							strings are identical, otherwise returns the
 *							difference between the first two differing bytes
 *							(treated as unsigned char values, so that ‘\200’
 *							is greater than ‘\0’,for example).
 *							Zero-length strings are always identical.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	i = 0;
	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	while (i < n)
	{
		if (s1ptr[i] != s2ptr[i])
			return (s1ptr[i] - s2ptr[i]);
		i++;
	}
	return (0);
}
