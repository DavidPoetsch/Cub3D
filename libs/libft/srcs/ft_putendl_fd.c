/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:42:09 by dpotsch           #+#    #+#             */
/*   Updated: 2024/11/23 11:42:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief	Outputs the string ’s’ to the given file descriptor 
 *				followed by a newline
 * @param s	The string to output.
 * @param fd	The file descriptor on which to write
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
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
	ft_putendl_fd(argv[1], fd);
	return (0);
}
 */
