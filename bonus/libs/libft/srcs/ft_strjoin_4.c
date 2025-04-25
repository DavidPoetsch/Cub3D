/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:32:38 by dpotsch           #+#    #+#             */
/*   Updated: 2025/03/17 16:33:12 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	get_strlen(char const *s1, char const *s2, char const *s3,
		char const *s4)
{
	size_t	len;

	len = 0;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (s3)
		len += ft_strlen(s3);
	if (s4)
		len += ft_strlen(s4);
	return (len);
}

/**
 * @brief Allocates (with malloc(3)) and returns a new string,
 *					which is the result of the concatenation of ’s1’ and ’s2’.
 * @param s1	The prefix string.
 * @param s2	The suffix string.
 * @return char*	Combined string.
 */
char	*ft_strjoin_4(char const *s1, char const *s2, char const *s3,
		char const *s4)
{
	char	*str;
	size_t	strlen;

	strlen = get_strlen(s1, s2, s3, s4);
	str = (char *)malloc((strlen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (strlen <= 0)
		return (str);
	if (s1)
		ft_strcat(str, s1);
	if (s2)
		ft_strcat(str, s2);
	if (s3)
		ft_strcat(str, s3);
	if (s4)
		ft_strcat(str, s4);
	return (str);
}

/*
int	main(int argc, char **argv)
{
	char const	*s1;
	char const	*s2;
	char		*dest;

	s1 = "Hello";
	s2 = "World";
	dest = ft_strjoin(s1, s2);
	printf("result = '%s'\n", dest);
	printf("dest len = %zu\n", ft_strlen((char const *)dest));
	if(dest != NULL)
		free(dest);
}
 */