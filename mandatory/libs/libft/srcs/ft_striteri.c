/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:14:18 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Applies the function ’f’ on each character of
 *				the string passed as argument, passing its index
 *				as first argument. Each character is passed by
 *				address to ’f’ to be modified if necessary.
 * @param s // The string on which to iterate.
 * @param f // The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	test_function(unsigned int i, char* c)
{
	(*c) += 32;
}

int	main(void)
{
	char	str[] = "HELLOWORLD";
	void	(*f)(unsigned int, char*);

	f = &test_function;
	printf("before:%s\n", str);
	ft_striteri(str, f);
	printf("after: %s\n", str);
	return (0);
}
 */