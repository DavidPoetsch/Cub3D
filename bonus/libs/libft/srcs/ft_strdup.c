/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:24:50 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strcpy(char *dest, const char *src);

/**
 * @brief	The  strdup()  function  returns a pointer to a new
 *				string which is a duplicate of the string s.
 *				Memory for the new string is obtained with malloc(3),
 *				and can be freed with free(3).
 * @param s	Source string.
 * @return char*	Returns a new string.
 */
char	*ft_strdup(const char *s)
{
	size_t	srclen;
	char	*dest;

	srclen = ft_strlen(s);
	dest = (char *)malloc((srclen + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int	main(void)
{
	char *test1 = "test";
	char *test2 = ft_strdup(test1);

	printf("%d\n", ft_strlen(test1));
	printf("%s\n", test2);
	printf("%d\n", ft_strlen(test2));
	free(test2);
	return (0);
} */