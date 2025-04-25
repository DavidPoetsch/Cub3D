/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:14:18 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Applies the function f to each character of the
 *				string s, passing its index as the first argument
 *				and the character itself as the second. A new
 *				string is created (using malloc(3)) to collect the
 *				results from the successive applications of f.
 * @param s	The string on which to iterate
 * @param f	The function to apply to each character.
 * @return char*	The string created from the successive applications of ’f’.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}

/*
char	test_function(unsigned int i, char c)
{
	return (c + 32);
}

int	main(void)
{
	char	*str;
	char	*res;
	char	(*f)(unsigned int, char);

	str = "TEST";
	f = &test_function;
	res = ft_strmapi(str, f);
	printf("before:%s\n", str);
	printf("after: %s\n", res);
	return (0);
}
 */