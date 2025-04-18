/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:30:02 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 08:49:12 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_enemy_dead(t_game *game)
{
	int fd;

	if (!game->enemy.alive)
	{
		fd = open(F_ENEMY_STATE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		return ;
		write(fd, "dead\n", 5);
		game->enemy.alive = true;
		game->enemy.health = 100;
	}
}

static void	check_player_alive(t_game *game)
{
	int read_bytes;
	char buf[10];
	int fd;

	fd = open(F_PLAYER_STATE, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, 10);
	if (ft_strnstr(buf, "dead", 10) != NULL)
	{
		game->player.alive = false;
		ft_printf("player died\n");
	}
}

static void	set_player_alive()
{
	int fd;

	fd = open(F_PLAYER_STATE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "alive\n", 6);
}

void	reset_player_pos(t_game *game)
{
	game->player.pos.x = game->player.start_x;
	game->player.pos.y = game->player.start_y;
	set_player_alive();
	game->player.alive = true;
}

void	check_player_state(t_game *game)
{
	set_enemy_dead(game);
	if (game->player.alive)
		check_player_alive(game);
	else
		reset_player_pos(game);
}
