/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:21:31 by dpotsch           #+#    #+#             */
/*   Updated: 2025/03/17 16:32:48 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	### The strcmp() function compares the two strings s1 and s2.
 *				The comparison is done using unsigned characters.
 *				It compares the whole strings.
 * @param s1	String 1 to compare.
 * @param s2	String 2 to compare.
 * @return bool	returns true if the two strings are identical.
 */
bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (true);
	if (!s1 || !s2)
		return (false);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (false);
	return (ft_strncmp(s1, s2, len1) == 0);
}
