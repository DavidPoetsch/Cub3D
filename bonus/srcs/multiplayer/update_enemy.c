/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:53:17 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 13:33:08 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update_enemy_pos(t_game *game)
{
	game->enemy.sprite->pos.x = game->enemy.pos.x;
	game->enemy.sprite->pos.y = game->enemy.pos.y;
	game->enemy.grid_old.x = game->enemy.grid.x;
	game->enemy.grid_old.y = game->enemy.grid.y;
	game->enemy.grid.x = floor(game->enemy.pos.x);
	game->enemy.grid.y = floor(game->enemy.pos.y);
	if (is_enemy(game->map.arr, game->enemy.grid_old.x, game->enemy.grid_old.y))
		game->map.arr[game->enemy.grid_old.y][game->enemy.grid_old.x] = OPEN;
	if (!is_collision(game->map.arr, game->enemy.grid.x, game->enemy.grid.y))
		game->map.arr[game->enemy.grid.y][game->enemy.grid.x] = ENEMY;
}
