/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:02:51 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 11:38:30 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	safe_move_x(t_game *game, t_vec *pos, double move_value)
{
	double	safe;

	safe = WALL_DIST_MIN;
	if (move_value < 0)
		safe = -safe;
	pos->x += move_value;
	if (pos->x <= 1.0 + WALL_DIST_MIN)
		pos->x -= move_value;
	else if (pos->x >= (game->map.width - (1.0 + WALL_DIST_MIN)))
		pos->x -= move_value;
	else if (is_collision(game->map.arr, floor(pos->x + safe), floor(pos->y)))
		pos->x -= move_value;
}

static void	safe_move_y(t_game *game, t_vec *pos, double move_value)
{
	double	safe;

	safe = WALL_DIST_MIN;
	if (move_value < 0)
		safe = -safe;
	pos->y += move_value;
	if (pos->y <= 1.0 + WALL_DIST_MIN)
		pos->y -= move_value;
	else if (pos->y >= (game->map.height - (1.0 + WALL_DIST_MIN)))
		pos->y -= move_value;
	else if (is_collision(game->map.arr, floor(pos->x), floor(pos->y + safe)))
		pos->y -= move_value;
}

static void	move_player_in_dir(t_game *game, t_player *player,
		double move_speed)
{
	if (game->keys.w_pressed && !game->keys.s_pressed)
	{
		safe_move_x(game, &player->pos, player->rotator.x * move_speed);
		safe_move_y(game, &player->pos, player->rotator.y * move_speed);
	}
	if (game->keys.s_pressed && !game->keys.w_pressed)
	{
		safe_move_x(game, &player->pos, -(player->rotator.x * move_speed));
		safe_move_y(game, &player->pos, -(player->rotator.y * move_speed));
	}
	if (game->keys.a_pressed && !game->keys.d_pressed)
	{
		safe_move_x(game, &player->pos, -(player->plane.x * move_speed));
		safe_move_y(game, &player->pos, -(player->plane.y * move_speed));
	}
	if (game->keys.d_pressed && !game->keys.a_pressed)
	{
		safe_move_x(game, &player->pos, player->plane.x * move_speed);
		safe_move_y(game, &player->pos, player->plane.y * move_speed);
	}
}

void	move_player(t_game *game)
{
	if (game->player.health <= 0)
		return ;
	move_player_in_dir(game, &game->player, game->delta_sec * MOVE_SPEED);
}
