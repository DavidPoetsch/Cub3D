/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:30:02 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 16:24:22 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_player_dead(t_game *game)
{
	game->player.alive = false;
	ft_printf("player died\n");
}

static void clear_file(char *path)
{
	int fd;

	fd = open(path, O_WRONLY | O_TRUNC);
	if (fd != -1)
		close(fd);
}

static void	received_restart_msg(t_game *game)
{
	game->state = GAME_RUNING;
	game->player.alive = true;
	game->player.health = 100;
	game->enemy.alive = true;
	game->enemy.health = 100;
}

static void	map_update(t_game *game, char buf[MSG_SIZE])
{
	int x;
	int y;
	char *str;

	str = ft_strchr(buf, '[');
	if (!str || (str + 1) == NULL)
		return;
	str++;
	y = ft_atoi(str);
	str = ft_strchr(buf, ',');
	if (!str || (str + 1) == NULL)
		return;
	str++;
	x = ft_atoi(str);
	str = ft_strchr(buf, '=');
	if (!str || (str + 1) == NULL)
		return;
	str++;
	if (x > 0 && x < game->map.width && y > 0 && y < game->map.height)
		game->map.arr[y][x] = *str;
}

static void	check_state(t_game *game)
{
	int read_bytes;
	char buf[MSG_SIZE];
	int fd;

	fd = open(F_PLAYER_STATE, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, MSG_SIZE);
	if (read_bytes > 0)
	{
		if (ft_strnstr(buf, "dead", 5) != NULL)
			set_player_dead(game);
		if (ft_strnstr(buf, "restart", 8) != NULL)
			received_restart_msg(game);
		if (ft_strnstr(buf, "map", 4) != NULL)
			map_update(game, buf);
		clear_file(F_PLAYER_STATE);
	}
}

void	check_player_state(t_game *game)
{
	if (!game->enemy.alive && game->player.alive && game->state == GAME_RUNING)
	{
		send_state("dead\n", true);
		game->restart_time = get_time_ms() + RESTART_TIME * 1000;
		game->state = GAME_RESTART;
	}
	check_state(game);
}
