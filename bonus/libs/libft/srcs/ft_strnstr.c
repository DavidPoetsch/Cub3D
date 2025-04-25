/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:46:02 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	The strnstr() function locates the first occurrence of the
 *				null-terminated string little in the string big, where not
 *				more than len characters are searched.  Characters that
 *				appear after a ‘\0’ character are not searched.
 * @param big
 * @param little
 * @param len
 * @return char*
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j < len)
		{
			if (big[i + j] == '\0')
				break ;
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*find;
	int		len;

	str = "Hello";
	find = "Hellotestse";
	len = 10;
	printf("1%s\n", ft_strnstr(str, find, len));
	printf("2%s", strnstr(str, find, len));
} */
