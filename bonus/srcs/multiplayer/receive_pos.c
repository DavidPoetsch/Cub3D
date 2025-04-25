/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:51:09 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 16:15:43 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vec	parse_position(const char *str)
{
	t_vec	pos;

	pos.x = strtof(str, (char **)&str);
	if (*str == ',')
		str++;
	pos.y = strtof(str, NULL);
	return (pos);
}

void	receive_pos(t_game *game)
{
	int		i;
	int		read_bytes;
	char	buf[MSG_SIZE];
	int		fd;

	fd = open(F_RCV_POS, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, MSG_SIZE);
	i = 0;
	if (read_bytes > 0)
		game->enemy.pos = parse_position(buf);
}
