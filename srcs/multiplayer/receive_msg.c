/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:37:25 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 09:20:54 by dpotsch          ###   ########.fr       */
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
	game->enemy.alive = true;
	game->enemy.health = 100;
	game->player.pos.x = game->enemy.pos_start.x;
	game->player.pos.y = game->enemy.pos_start.y;
	game->player.ammo = AMMO_MAX;
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
	if (*str == DOOR)
		move_player_if_in_door(game, set_pos(x, y));
}

static void	msg_health_pack(t_game *game)
{
	if (game->enemy.alive && game->enemy.health > 0)
		game->enemy.health += HEALTH_PACK;
}

void	receive_msg(t_game *game)
{
	int		read_bytes;
	char	buf[MSG_SIZE + 1];
	int		fd;

	fd = open(F_RCV_MSG, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, MSG_SIZE);
	if (read_bytes > 0)
	{
		buf[read_bytes] = '\0';
		if (ft_strnstr(buf, "dead", 5) != NULL)
			msg_player_died(game);
		else if (ft_strnstr(buf, "restart", 8) != NULL)
			msg_restart(game);
		else if (ft_strnstr(buf, "map", 4) != NULL)
			msg_map_update(game, buf);
		else if (ft_strnstr(buf, "health", 7) != NULL)
			msg_health_pack(game);
		ft_printf("[RCV]: %s", buf);
		clear_file(F_RCV_MSG);
	}
}
