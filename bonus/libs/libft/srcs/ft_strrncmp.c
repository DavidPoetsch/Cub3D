/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:46:02 by dpotsch           #+#    #+#             */
/*   Updated: 2025/02/04 11:16:50 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The strrncmp() function compares the two strings s1 and s2.
 *				The comparison is done using unsigned characters.
 *				It compares only the last (at most) n bytes  of  s1  and s2.
 * @param s1	String 1 to compare.
 * @param s2	String 2 to compare.
 * @param n	Amount of bytes to compare.
 * @return int	returns zero if the two strings are identical,
 *							otherwise returns the difference between the first
 *							two differing characters (treated as unsigned char).
 *							Zero-length strings are always identical.
 */
int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t			len1;
	size_t			len2;
	size_t			start1;
	size_t			start2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	start1 = 0;
	start2 = 0;
	if (len1 > n)
		start1 = len1 - n;
	if (len2 > n)
		start2 = len2 - n;
	s1 += start1;
	s2 += start2;
	return (ft_strncmp(s1, s2, n));
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*test1;
	char	*test2;
	int		n;

	test1 = "   abc";
	test2 = " abc";
	n = 5;
	printf("%d\n", ft_strrncmp(test1, test2, n));
} */
