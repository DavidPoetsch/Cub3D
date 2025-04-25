/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:42:09 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 11:32:56 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * @param n	The integer to output.
 * @param fd	The file descriptor on which to write.
 */
void	ft_printf_putnbr(long long n, int fd)
{
	char	c;

	if (n == LLONG_MIN)
	{
		add_to_buffer(fd, "-9223372036854775808", 20);
		return ;
	}
	if (n < 0)
	{
		add_to_buffer(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_printf_putnbr(n / 10, fd);
	}
	c = (n % 10) + '0';
	add_to_buffer(fd, &c, 1);
}
