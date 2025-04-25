/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:08:30 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 10:49:52 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_specifier(t_format_specifier *fs, int file_descriptor)
{
	fs->invalid_eol = false;
	fs->fd = file_descriptor;
}

int	apply_format(va_list *parg, t_format_specifier *fs)
{
	int	result;

	result = 0;
	if (fs->invalid)
		return (result);
	if (fs->type.c)
		result = output_c(va_arg((*parg), int), fs);
	else if (fs->type.s)
		result = output_s(va_arg((*parg), char *), fs);
	else if (fs->type.p)
		result = output_p(va_arg((*parg), void *), fs);
	else if (fs->type.d)
		result = output_d(va_arg((*parg), int), fs);
	else if (fs->type.i)
		result = output_i(va_arg((*parg), int), fs);
	else if (fs->type.u)
		result = output_u(va_arg((*parg), unsigned int), fs);
	else if (fs->type.x_lo)
		result = output_x_lo(va_arg((*parg), unsigned int), fs);
	else if (fs->type.x_up)
		result = output_x_up(va_arg((*parg), unsigned int), fs);
	else if (fs->percent)
		result = output_percent(fs);
	return (result);
}

void	check_format_specifiers(const char *format, size_t *i,
		t_format_specifier *fs)
{
	(*i)++;
	fs->invalid_eol = false;
	check_flags(format, i, fs);
	check_width(format, i, fs);
	check_precision(format, i, fs);
	check_specifier(format, i, fs);
	validate_format(fs);
}

int	write_default(const char *format, size_t *i, t_format_specifier *fs,
		int i_percent)
{
	int	result;

	result = 0;
	if (fs->invalid && !fs->invalid_eol)
	{
		(*i) = i_percent;
		result = add_to_buffer(fs->fd, &format[*i], 1);
		(*i)++;
		return (result);
	}
	if (format[*i] != '\0' && format[*i] != '%')
	{
		result = add_to_buffer(fs->fd, &format[*i], 1);
		(*i)++;
	}
	return (result);
}
