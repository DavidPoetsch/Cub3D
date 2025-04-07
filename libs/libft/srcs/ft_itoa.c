/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:38:42 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	get_len(long n, int *len);
static void	convert_number(long n, int len, char *res);

/**
 * @brief Allocates (with malloc(3)) and returns a string
 *				representing the integer received as an argument.
 *				Negative numbers must be handled.
 * @param n	The integer to convert.
 * @return char*	The string representing the integer.
 *								NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = 0;
	get_len(num, &len);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (num < 0)
	{
		num = -num;
		res[0] = '-';
	}
	convert_number(num, len, res);
	res[len] = '\0';
	return (res);
}

static void	get_len(long n, int *len)
{
	if (n < 0)
	{
		n = -n;
		(*len)++;
	}
	if (n >= 10)
		get_len(n / 10, len);
	(*len)++;
}

static void	convert_number(long n, int len, char *res)
{
	char	c;

	if (n >= 10)
		convert_number(n / 10, len - 1, res);
	if (len - 1 >= 0)
	{
		c = (n % 10) + '0';
		res[len - 1] = c;
	}
}

/*
int	main(void)
{
	printf("res = '%s'\n", ft_itoa(2147483647));
	printf("res = '%s'\n", ft_itoa(-2147483648));
	printf("res = '%s'\n", ft_itoa(-100));
	printf("res = '%s'\n", ft_itoa(-10));
	printf("res = '%s'\n", ft_itoa(-1));
	printf("res = '%s'\n", ft_itoa(-0));
	printf("res = '%s'\n", ft_itoa(123));
	return (0);
}
 */