/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:39:20 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/04 09:57:49 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c Prints a single character.
int	output_c(int c, t_format_specifier *fs)
{
	int		result;
	size_t	strlen;
	char	oc;

	oc = (unsigned char)c;
	strlen = 1;
	result = right_justify(strlen, fs);
	result += add_to_buffer(fs->fd, &oc, 1);
	result += left_justify(strlen, fs);
	return (result);
}

// %s Prints a string (as defined by the common C convention).
int	output_s(char *str, t_format_specifier *fs)
{
	int		result;
	int		strlen;

	strlen = get_str_precision(str, fs);
	if (!str)
		str = "(null)";
	result = right_justify(strlen, fs);
	result += add_to_buffer(fs->fd, str, strlen);
	result += left_justify(strlen, fs);
	return (result);
}

// %% Prints a percent sign.
int	output_percent(t_format_specifier *fs)
{
	return (add_to_buffer(fs->fd, "%", 1));
}
