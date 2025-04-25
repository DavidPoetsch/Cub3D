/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:46:02 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The strncmp() function compares the two strings s1 and s2.
 *				The comparison is done using unsigned characters.
 *				It compares only the first (at most) n bytes  of  s1  and s2.
 * @param s1	String 1 to compare.
 * @param s2	String 2 to compare.
 * @param n	Amount of bytes to compare.
 * @return int	returns zero if the two strings are identical,
 *							otherwise returns the difference between the first
 *							two differing characters (treated as unsigned char).
 *							Zero-length strings are always identical.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
		if (s1ptr[i] == '\0' || s2ptr[i] == '\0')
			return (s1ptr[i] - s2ptr[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1ptr[i] - s2ptr[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*test1;
	char	*test2;
	int		n;

	test1 = "abc";
	test2 = "abc";
	n = 7;
	printf("%d\n", ft_strncmp(test1, test2, n));
	printf("%d\n", strncmp(test1, test2, n));
}
 */