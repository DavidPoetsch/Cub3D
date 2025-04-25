/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:38:31 by dpotsch           #+#    #+#             */
/*   Updated: 2025/02/05 12:22:22 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		in_charset(char c, char const *set);
static size_t	get_start_index(char const *s1, char const *set);
static size_t	get_end_index(char const *s1, char const *set, size_t len);

/**
 * @brief	Allocates (with malloc(3)) and returns a copy of
 *				’s1’ with the characters specified in ’set’ removed
 *				from the beginning and the end of the string.
 * @param s1 The string to be trimmed;
 * @param set The reference set of characters to trim;
 * @return char*	The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i_end;
	size_t	len;
	char	*res;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i_start = get_start_index(s1, set);
	i_end = get_end_index(s1, set, len);
	len = 0;
	if (i_end >= i_start)
		len = i_end - i_start + 1;
	if (i_end == i_start && in_charset(s1[i_end], set))
		len = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + i_start, len + 1);
	res[len] = '\0';
	return (res);
}

static int	in_charset(char c, char const *set)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start_index(char const *s1, char const *set)
{
	size_t	i_start;

	i_start = 0;
	while (in_charset(s1[i_start], set) && s1[i_start] != '\0')
		i_start++;
	return (i_start);
}

static size_t	get_end_index(char const *s1, char const *set, size_t len)
{
	size_t	i_end;

	if (len == 0)
		return (0);
	i_end = len - 1;
	while (i_end > 0 && in_charset(s1[i_end], set))
		i_end--;
	return (i_end);
}

/* #include <stdio.h>
int	main(void)
{
	char	*s1;
	char	*set;
	char	*res;

	s1 = " \t\n \t\n  ";
	set = " \t\n";
	res = ft_strtrim(s1, set);
	printf("before ='%s'\n", s1);
	printf("trimmed='%s'\n", res);
	return (0);
} */
