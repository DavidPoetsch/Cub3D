/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_interactions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:26:24 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 15:54:32 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_interactions(t_game *game, t_raycast *rc)
{
	int	tile;

	tile = game->map.arr[rc->map_y][rc->map_x];
	if (tile == DOOR && rc->wall_dist <= INTERACT_DIST && game->keys.e_pressed)
	{
		game->map.arr[rc->map_y][rc->map_x] = '0';
		game->map.arr[rc->map_y][rc->map_x - 1] = 'D';
	}
	if (tile == LOCK && rc->wall_dist <= INTERACT_DIST && game->keys.e_pressed && game->player.keys == UNLOCK)
	{
		game->map.arr[rc->map_y][rc->map_x] = '0';
	}
	if (rc->enemy_hit && game->mouse.lmb_pressed)
	{
		game->mouse.lmb_pressed = 0;
		printf("Health: %d\n", game->enemy.health);
		game->enemy.health -= 10;
		if (game->enemy.health <= 0)
		{
			game->enemy.alive = false;
			game->map.arr[game->enemy.grid.y][game->enemy.grid.x] = '0';
		}
	}
}
