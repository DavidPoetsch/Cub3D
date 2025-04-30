/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:42:09 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/30 13:58:22 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	Outputs the string ’s’ to the given file descriptor.
 * @param s	The string to output.
 * @param fd	The file descriptor on which to write
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
/*
#include <fcntl.h>   // For open()
#include <stdio.h>
#include <unistd.h>  // For read(), write(), close()

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc <= 1)
	{
		printf("arguments wrong\n");
		return (1);
	}
	fd = open("test.txt", O_WRONLY);
	ft_putstr_fd(argv[1], fd);
	return (0);
}
 */
