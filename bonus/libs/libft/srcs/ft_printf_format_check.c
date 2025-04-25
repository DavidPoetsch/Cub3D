/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:08:24 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../includes/libft.h"

void	check_flags(const char *format, size_t *i, t_format_specifier *fs)
{
	while (format[*i] != '\0' && format[*i] != '%')
	{
		if (format[*i] == '-')
			fs->flags.left_justify = true;
		else if (format[*i] == '0')
			fs->flags.zero_padding = true;
		else if (format[*i] == '#')
			fs->flags.alternate_form = true;
		else if (format[*i] == '+')
			fs->flags.explicit_sign = true;
		else if (format[*i] == ' ')
			fs->flags.space = true;
		else
			break ;
		(*i)++;
	}
	if (format[*i] == '\0')
		fs->invalid_eol = true;
}

void	check_width(const char *format, size_t *i, t_format_specifier *fs)
{
	int	number;

	number = 0;
	while (ft_isdigit(format[*i]))
	{
		number = (number * 10) + format[*i] - '0';
		(*i)++;
		fs->width = number;
	}
}

void	check_precision(const char *format, size_t *i, t_format_specifier *fs)
{
	int	number;

	number = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		fs->flags.precision = true;
		fs->precision = 0;
		while (ft_isdigit(format[*i]))
		{
			number = (number * 10) + format[*i] - '0';
			(*i)++;
			fs->precision = number;
		}
	}
}

void	check_specifier(const char *format, size_t *i, t_format_specifier *fs)
{
	if (format[*i] != '\0')
	{
		if (format[*i] == 'c')
			fs->type.c = true;
		else if (format[*i] == 's')
			fs->type.s = true;
		else if (format[*i] == 'p')
			fs->type.p = true;
		else if (format[*i] == 'd')
			fs->type.d = true;
		else if (format[*i] == 'i')
			fs->type.i = true;
		else if (format[*i] == 'u')
			fs->type.u = true;
		else if (format[*i] == 'x')
			fs->type.x_lo = true;
		else if (format[*i] == 'X')
			fs->type.x_up = true;
		else if (format[*i] == '%')
			fs->percent = true;
		else
			fs->invalid = true;
		(*i)++;
	}
}

void	validate_format(t_format_specifier *fs)
{
	if (fs->flags.space && fs->flags.explicit_sign)
		fs->flags.space = false;
	if (fs->flags.left_justify)
		fs->flags.zero_padding = false;
	if (fs->type.u)
		fs->flags.explicit_sign = false;
}
