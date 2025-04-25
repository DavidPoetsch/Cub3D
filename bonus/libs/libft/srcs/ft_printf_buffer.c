/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:15:33 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_print_buff_handler	*print_buffer_handler(void)
{
	static t_print_buff_handler	pbh;

	return (&pbh);
}

void	flush_print_buffer(int fd)
{
	t_print_buff_handler	*pbh;

	pbh = print_buffer_handler();
	if (!pbh || pbh->is_empty)
		return ;
	write(fd, pbh->buff, pbh->i);
	pbh->i = 0;
	pbh->is_empty = true;
}

int	add_to_buffer(int fd, const char *str, size_t len)
{
	t_print_buff_handler	*pbh;
	size_t					i_str;
	size_t					str_len;

	pbh = print_buffer_handler();
	str_len = ft_strlen(str);
	if (pbh->i + str_len > PRINT_BUFFER_SIZE)
		flush_print_buffer(fd);
	i_str = 0;
	while (str[i_str] != '\0' && i_str < len)
	{
		if (pbh->i >= PRINT_BUFFER_SIZE)
			flush_print_buffer(fd);
		pbh->buff[pbh->i] = str[i_str];
		i_str++;
		pbh->i++;
		pbh->is_empty = false;
	}
	if (pbh->i >= PRINT_BUFFER_SIZE)
		flush_print_buffer(fd);
	return (len);
}
