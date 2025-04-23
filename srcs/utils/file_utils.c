/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:20 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 14:36:39 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_file(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_TRUNC);
	if (fd != -1)
		close(fd);
}

bool	file_is_empty(char *path)
{
	int		fd;
	char	buf;
	bool	empyt;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (true);
	empyt = true;
	if (read(fd, &buf, 1) > 0)
		empyt = false;
	close(fd);
	return (empyt);
}
