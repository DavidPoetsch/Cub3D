/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:51:06 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The strchr() function returns a pointer to the last
 *				occurrence of the character c in the string s.
 * @param s	The string to check.
 * @param c	The character to find.
 * @return char*	Returns a pointer to the found character.
 *								NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cfind;
	char	*ptrfound;

	i = 0;
	cfind = (char)c;
	ptrfound = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == cfind)
			ptrfound = (char *)&s[i];
		i++;
	}
	if (cfind == '\0')
		ptrfound = (char *)&s[i];
	return (ptrfound);
}
