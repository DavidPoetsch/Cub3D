/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:55:54 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 09:58:52 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_hex_rec(size_t nbr, const char *base, int *result, int fd)
{
	if (nbr >= 16)
		putnbr_hex_rec((nbr / 16), base, result, fd);
	if (fd >= 0)
		add_to_buffer(fd, &base[nbr % 16], 1);
	(*result)++;
}

int	putnbr_hex(size_t number, const char *base, const int fd)
{
	int	result;

	result = 0;
	putnbr_hex_rec(number, base, &result, fd);
	return (result);
}

int	get_hex_len(size_t number)
{
	int	result;

	result = 0;
	putnbr_hex_rec(number, BASE_LO, &result, -1);
	return (result);
}
