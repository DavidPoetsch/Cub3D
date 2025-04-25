/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:08:30 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../includes/libft.h"

void	reset_format_specifier(t_format_specifier *fs)
{
	fs->flags.left_justify = false;
	fs->flags.zero_padding = false;
	fs->flags.alternate_form = false;
	fs->flags.explicit_sign = false;
	fs->flags.space = false;
	fs->flags.precision = false;
	fs->width = -1;
	fs->precision = -1;
	fs->invalid = false;
	fs->percent = false;
	fs->type.c = false;
	fs->type.s = false;
	fs->type.p = false;
	fs->type.d = false;
	fs->type.i = false;
	fs->type.u = false;
	fs->type.x_lo = false;
	fs->type.x_up = false;
}

void	get_num_len(long long num, int *result)
{
	(*result)++;
	if (num == LLONG_MIN)
	{
		(*result) = 20;
		return ;
	}
	if (num < 0)
	{
		num = -num;
	}
	if (num >= 10)
	{
		get_num_len(num / 10, result);
	}
}

int	get_num_len_formatted(long long num, int numlen, t_format_specifier *fs)
{
	int	numlen_formatted;

	numlen_formatted = numlen;
	if (num == 0 && fs->precision == 0)
		numlen_formatted = 0;
	else if (fs->precision >= numlen && fs->flags.precision)
		numlen_formatted = fs->precision;
	else if (fs->precision >= 0 && fs->precision < numlen
		&& fs->flags.precision)
		numlen_formatted = numlen;
	else if (fs->width > numlen && fs->flags.zero_padding)
		numlen_formatted = fs->width;
	if (!fs->type.x_lo && !fs->type.x_up && !fs->type.u)
	{
		if ((num >= 0 && fs->flags.explicit_sign) || num < 0)
			numlen_formatted++;
		if (fs->flags.space && num >= 0)
			numlen_formatted++;
	}
	return (numlen_formatted);
}

int	get_num_len_formatted_p(size_t num, int numlen, t_format_specifier *fs)
{
	int	numlen_formatted;

	numlen_formatted = numlen;
	if (num == 0 && fs->precision == 0)
		numlen_formatted = 0;
	else if (fs->precision >= numlen && fs->flags.precision)
		numlen_formatted = fs->precision;
	else if (fs->precision > 0 && fs->precision < numlen && fs->flags.precision)
		numlen_formatted = numlen;
	else if (fs->width > numlen && fs->flags.zero_padding)
		numlen_formatted = fs->width;
	if (fs->flags.explicit_sign)
		numlen_formatted++;
	if (fs->flags.space)
		numlen_formatted++;
	return (numlen_formatted);
}

int	get_str_precision(char *str, t_format_specifier *fs)
{
	int	strlen;

	if (!str)
	{
		strlen = 6;
		if (fs->flags.precision && fs->precision < 6)
			strlen = 0;
		return (strlen);
	}
	strlen = (int)ft_strlen(str);
	if (!fs->flags.precision)
		return (strlen);
	if (fs->precision < strlen)
		return (fs->precision);
	return (strlen);
}
