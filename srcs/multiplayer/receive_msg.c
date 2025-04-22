/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:37:25 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 16:33:57 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	msg_player_died(t_game *game)
{
	game->player.alive = false;
}

static void	msg_restart(t_game *game)
{
	game->state = GAME_RUNING;
	game->player.alive = true;
	game->player.health = 100;
	game->enemy.alive = true;
	game->enemy.health = 100;
}

static void	msg_map_update(t_game *game, char buf[MSG_SIZE])
{
	int		x;
	int		y;
	char	*str;

	str = ft_strchr(buf, '[');
	if (!str || (str + 1) == NULL)
		return ;
	str++;
	y = ft_atoi(str);
	str = ft_strchr(buf, ',');
	if (!str || (str + 1) == NULL)
		return ;
	str++;
	x = ft_atoi(str);
	str = ft_strchr(buf, '=');
	if (!str || (str + 1) == NULL)
		return ;
	str++;
	if (x > 0 && x < game->map.width && y > 0 && y < game->map.height)
		game->map.arr[y][x] = *str;
}

void	receive_msg(t_game *game)
{
	int		read_bytes;
	char	buf[MSG_SIZE];
	int		fd;

	fd = open(F_RCV_MSG, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, MSG_SIZE);
	if (read_bytes > 0)
	{
		if (ft_strnstr(buf, "dead", 5) != NULL)
			msg_player_died(game);
		if (ft_strnstr(buf, "restart", 8) != NULL)
			msg_restart(game);
		if (ft_strnstr(buf, "map", 4) != NULL)
			msg_map_update(game, buf);
		ft_printf("[RCV]: %s", buf);
		clear_file(F_RCV_MSG);
	}
}
