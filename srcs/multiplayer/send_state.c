/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:00:12 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 16:40:10 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool file_is_empty(char *path)
{
	int fd;
	char *buf[3];
	bool empyt;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (true);
	empyt = true;
	if (read(fd, buf, 1) > 0)
		empyt = false;
	close(fd);
	return (empyt);
}

int send_state(char *msg, bool send_now)
{
	int	fd;

	if (!msg)
		return (ERROR);
	if (!send_now && !file_is_empty(F_ENEMY_STATE))
		return (ERROR);
	fd = open(F_ENEMY_STATE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ERROR);
	write(fd, msg, ft_strlen(msg));
	return (SUCCESS);
}
