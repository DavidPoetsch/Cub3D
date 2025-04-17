/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:30:02 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 16:57:34 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_enemy_dead(t_game *game)
{
	static bool printed;
	int fd;
	char *file;

	if (!printed && !game->enemy.alive)
	{
		file = "./test/enemy_state.txt";
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		return ;
		write(fd, "dead\n", 5);
	}
	if (!game->enemy.alive)
		printed = true;
	else
		printed = false;
}

void	check_player_alive(t_game *game)
{
	int read_bytes;
	char buf[10];
	int fd;
	char *file;

	file = "./test/player_state.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	read_bytes = read(fd, buf, 10);
	if (ft_strnstr(buf, "dead", 10) != NULL)
	{
		game->player.alive = false;
		printf("player died\n");
	}
}

void	check_player_state(t_game *game)
{
	set_enemy_dead(game);
	if (game->player.alive)
		check_player_alive(game);
}
