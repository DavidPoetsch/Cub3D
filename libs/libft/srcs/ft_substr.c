/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:51:05 by dpotsch           #+#    #+#             */
/*   Updated: 2025/02/12 09:34:01 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	Allocates (with malloc(3)) and returns a substring
 *				from the string ’s’.
 *				The substring begins at index ’start’ and is of
 *				maximum size ’len’.
 * @param s	The string from which to create the substring.
 * @param start	The start index of the substring in the string ’s’.
 * @param len	The maximum length of the substring.
 * @return char*	The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	res_len;
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	res_len = 0;
	if (start < s_len)
		res_len = s_len - start;
	if (res_len > len)
		res_len = len;
	substr = (char *)malloc((res_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < res_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int	main(void)
{
	char	*test;
	char	*substr;

	test = "HelloWorld";
	substr = ft_substr(test, 5, 5);
	printf("substr='%s'\n", substr);
	return (0);
}
 */