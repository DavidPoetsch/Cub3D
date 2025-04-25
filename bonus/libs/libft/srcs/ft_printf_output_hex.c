/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:41:48 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 10:50:45 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %p The void * pointer argument has to be printed in hexadecimal format.
int	output_p(void *ptr, t_format_specifier *fs)
{
	int	result;
	int	numlen_raw;
	int	numlen;

	result = 0;
	if (!ptr)
	{
		fs->flags.precision = false;
		return (output_s(NULL_PTR_STR, fs));
	}
	numlen_raw = get_hex_len((size_t)ptr);
	numlen = 2;
	numlen += get_num_len_formatted_p((size_t)ptr, numlen_raw, fs);
	result += right_justify(numlen, fs);
	if (fs->flags.explicit_sign)
		result += add_to_buffer(fs->fd, "+", 1);
	if (fs->flags.space && !fs->flags.explicit_sign)
		result += add_to_buffer(fs->fd, " ", 1);
	result += add_to_buffer(fs->fd, "0x", 2);
	result += zero_padding(1, numlen_raw, fs);
	result += putnbr_hex((size_t)ptr, BASE_LO, fs->fd);
	result += left_justify(numlen, fs);
	return (result);
}

// %x Prints a number in hexadecimal (base 16) lowercase format.
int	output_x_lo(unsigned int num, t_format_specifier *fs)
{
	int			result;
	int			numlen_raw;
	int			numlen;
	long long	tnum;

	tnum = num;
	result = 0;
	numlen_raw = 0;
	if (fs->flags.alternate_form)
		fs->width -= 2;
	numlen_raw += get_hex_len((size_t)tnum);
	if (num == 0 && fs->precision == 0)
		numlen_raw = 0;
	numlen = get_num_len_formatted(tnum, numlen_raw, fs);
	result += right_justify(numlen, fs);
	if (numlen_raw > 0)
	{
		if (fs->flags.alternate_form && num != 0)
			result += add_to_buffer(fs->fd, "0x", 2);
		result += zero_padding(num, numlen_raw, fs);
		result += putnbr_hex((size_t)tnum, BASE_LO, fs->fd);
	}
	result += left_justify(numlen, fs);
	return (result);
}

// %X Prints a number in hexadecimal (base 16) lowercase format.
int	output_x_up(unsigned int num, t_format_specifier *fs)
{
	int			result;
	int			numlen_raw;
	int			numlen;
	long long	tnum;

	tnum = num;
	result = 0;
	numlen_raw = 0;
	if (fs->flags.alternate_form)
		fs->width -= 2;
	numlen_raw += get_hex_len((size_t)tnum);
	if (num == 0 && fs->precision == 0)
		numlen_raw = 0;
	numlen = get_num_len_formatted(tnum, numlen_raw, fs);
	result += right_justify(numlen, fs);
	if (numlen_raw > 0)
	{
		if (fs->flags.alternate_form && num != 0)
			result += add_to_buffer(fs->fd, "0X", 2);
		result += zero_padding(num, numlen_raw, fs);
		result += putnbr_hex((size_t)tnum, BASE_UP, fs->fd);
	}
	result += left_justify(numlen, fs);
	return (result);
}
