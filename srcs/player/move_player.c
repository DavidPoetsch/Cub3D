/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:02:51 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 12:07:50 by dpotsch          ###   ########.fr       */
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

void	move_player(t_game *game)
{
	t_player	*player;

	if (!game->player.alive)
		return ;

	player = &game->player;
	if (game->keys.w_pressed && !game->keys.s_pressed)
	{
		safe_move_x(game, &player->pos, player->rotator.x * MOVE_SPEED);
		safe_move_y(game, &player->pos, player->rotator.y * MOVE_SPEED);
	}
	if (game->keys.s_pressed && !game->keys.w_pressed)
	{
		safe_move_x(game, &player->pos, -(player->rotator.x * MOVE_SPEED));
		safe_move_y(game, &player->pos, -(player->rotator.y * MOVE_SPEED));
	}
	if (game->keys.a_pressed && !game->keys.d_pressed)
	{
		safe_move_x(game, &player->pos, -(player->plane.x * MOVE_SPEED));
		safe_move_y(game, &player->pos, -(player->plane.y * MOVE_SPEED));
	}
	if (game->keys.d_pressed && !game->keys.a_pressed)
	{
		safe_move_x(game, &player->pos, player->plane.x * MOVE_SPEED);
		safe_move_y(game, &player->pos, player->plane.y * MOVE_SPEED);
	}
}
