/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:09:52 by dpotsch           #+#    #+#             */
/*   Updated: 2025/03/07 15:34:39 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_space(char c);

/**
 * @brief				The function converts the initial portion of the string
 *							pointed to by nptr to int.
 * @param nptr	Pointer to a string
 * @return int	The converted value or 0 on error.
 */
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		number;
	short	is_neg;

	i = 0;
	number = 0;
	is_neg = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			is_neg = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		number = (number * 10) + nptr[i] - '0';
		i++;
	}
	if (is_neg)
		number = -number;
	return (number);
}

static int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

/* 
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	printf("00 %d\n", ft_atoi("  +"));
	printf("0 %d\n", ft_atoi(" 1"));
	printf("1 %d\n", ft_atoi(" 1325632167"));
	printf("2 %d\n", ft_atoi(" -1325632167"));
	printf("3 %d\n", ft_atoi("--1325632167"));
	printf("4 %d\n", ft_atoi("+0"));
	printf("5 %d\n", ft_atoi(" 1325632"));
	printf("6 %d\n", ft_atoi("	--2097121301"));
	printf("7 %d\n", ft_atoi("+175074925"));
	printf("8 %d\n", ft_atoi(" -2147483648"));
	printf("9 %d\n", ft_atoi(" -2147483647"));
	printf("10 %d\n", ft_atoi(" 0"));
	return (0);
}
 */