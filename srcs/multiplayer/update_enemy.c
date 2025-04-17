/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:53:17 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 15:33:02 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void update_pos(t_enemy *enemy, double move_x, double move_y)
{
	printf("dx: %f, dy: %f\n", move_x, move_y);
	printf("px: %f, py: %f\n", enemy->pos.x, enemy->pos.y);
	enemy->pos.x += move_x;
	enemy->pos.y += move_y;
	printf("px: %f, py: %f\n", enemy->pos.x, enemy->pos.y);
	printf("sx: %f, sy: %f\n", enemy->sprite.pos.x, enemy->sprite.pos.y);
	enemy->sprite.pos.x = enemy->pos.x;
	enemy->sprite.pos.y = enemy->pos.y;
	printf("sx: %f, sy: %f\n", enemy->sprite.pos.x, enemy->sprite.pos.y);
}

void update_enemy_pos(t_game *game)
{
	double move_x;
	double move_y;

	move_x = (game->player.pos.x - game->enemy.pos.x) / 10;
	move_y = (game->player.pos.y - game->enemy.pos.y) / 10;
	update_pos(&game->enemy, move_x, move_y);
} */


void update_enemy_pos(t_game *game)
{
	game->enemy.sprite.pos.x = game->enemy.pos.x;
	game->enemy.sprite.pos.y = game->enemy.pos.y;
	game->enemy.grid_old.x = game->enemy.grid.x;
	game->enemy.grid_old.y = game->enemy.grid.y;
	game->enemy.grid.x = floor(game->enemy.pos.x);
	game->enemy.grid.y = floor(game->enemy.pos.y);
	game->map.arr[game->enemy.grid_old.y][game->enemy.grid_old.x] = '0';
	game->map.arr[game->enemy.grid.y][game->enemy.grid.x] = 'X';
}