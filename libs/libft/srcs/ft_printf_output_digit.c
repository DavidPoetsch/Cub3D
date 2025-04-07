/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:43 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 10:52:52 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d Prints a decimal (base 10) number.
int	output_d(int num, t_format_specifier *fs)
{
	int			result;
	int			numlen;
	int			numlen_raw;
	long long	number;

	numlen_raw = 0;
	number = num;
	get_num_len(num, &numlen_raw);
	if (num == 0 && fs->precision == 0)
		numlen_raw = 0;
	numlen = get_num_len_formatted(num, numlen_raw, fs);
	result = numlen_raw;
	result += right_justify(numlen, fs);
	result += add_sign(&number, fs);
	if (numlen_raw > 0)
	{
		result += zero_padding(num, numlen_raw, fs);
		ft_printf_putnbr(number, fs->fd);
	}
	result += left_justify(numlen, fs);
	return (result);
}

// %i Prints an integer in base 10.
int	output_i(int num, t_format_specifier *fs)
{
	int			result;
	int			numlen;
	int			numlen_raw;
	long long	number;

	numlen_raw = 0;
	number = num;
	get_num_len(num, &numlen_raw);
	if (num == 0 && fs->precision == 0)
		numlen_raw = 0;
	numlen = get_num_len_formatted(num, numlen_raw, fs);
	result = numlen_raw;
	result += right_justify(numlen, fs);
	result += add_sign(&number, fs);
	if (numlen_raw > 0)
	{
		result += zero_padding(num, numlen_raw, fs);
		ft_printf_putnbr(number, fs->fd);
	}
	result += left_justify(numlen, fs);
	return (result);
}

// %u Prints an unsigned decimal (base 10) number.
int	output_u(unsigned int num, t_format_specifier *fs)
{
	int			result;
	int			numlen;
	int			numlen_raw;
	long long	number;

	numlen_raw = 0;
	number = num;
	get_num_len(num, &numlen_raw);
	if (num == 0 && fs->precision == 0)
		numlen_raw = 0;
	numlen = get_num_len_formatted(num, numlen_raw, fs);
	result = numlen_raw;
	result += right_justify(numlen, fs);
	if (numlen_raw > 0)
	{
		result += zero_padding(num, numlen_raw, fs);
		ft_printf_putnbr(number, fs->fd);
	}
	result += left_justify(numlen, fs);
	return (result);
}
