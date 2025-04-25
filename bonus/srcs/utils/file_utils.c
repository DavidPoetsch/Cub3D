/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:20 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 15:07:38 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	clear_file(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == FAILED)
		return (ft_eprintf("Error: failed to open file '%s'\n", path));
	close(fd);
	return (SUCCESS);
}

bool	file_is_empty(char *path)
{
	int		fd;
	char	buf;
	bool	empyt;

	fd = open(path, O_RDONLY);
	if (fd == FAILED)
		return (false);
	empyt = true;
	if (read(fd, &buf, 1) > 0)
		empyt = false;
	close(fd);
	return (empyt);
}
