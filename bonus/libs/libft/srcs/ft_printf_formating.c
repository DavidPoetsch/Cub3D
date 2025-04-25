/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formating.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:14:30 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 10:53:27 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	left_justify(int strlen, t_format_specifier *fs)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!fs->flags.left_justify)
		return (result);
	if (fs->width < 0)
		return (result);
	while ((strlen + i) < fs->width)
	{
		result += add_to_buffer(fs->fd, " ", 1);
		i++;
	}
	return (result);
}

int	right_justify(int strlen, t_format_specifier *fs)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (fs->flags.left_justify)
		return (result);
	if (fs->width < 0)
		return (result);
	while ((strlen + i) < fs->width)
	{
		result += add_to_buffer(fs->fd, " ", 1);
		i++;
	}
	return (result);
}

int	zero_padding(long long num, int numlen_raw, t_format_specifier *fs)
{
	int		result;
	size_t	i;
	size_t	padding;

	result = 0;
	i = 0;
	padding = 0;
	if (fs->precision >= numlen_raw && fs->flags.precision)
		padding = fs->precision - numlen_raw;
	else if (fs->width > numlen_raw && fs->flags.zero_padding
		&& !fs->flags.precision)
	{
		padding = fs->width - numlen_raw;
		if (((num >= 0 && fs->flags.explicit_sign) || num < 0) && padding >= 1)
			padding--;
	}
	while (i < padding)
	{
		result += add_to_buffer(fs->fd, "0", 1);
		i++;
	}
	return (result);
}

int	add_sign(long long *num, t_format_specifier *fs)
{
	if (*num < 0)
	{
		(*num) = -(*num);
		return (add_to_buffer(fs->fd, "-", 1));
	}
	if (fs->flags.explicit_sign)
		return (add_to_buffer(fs->fd, "+", 1));
	if (fs->flags.space)
		return (add_to_buffer(fs->fd, " ", 1));
	return (0);
}
