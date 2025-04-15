/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:02:51 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 16:58:29 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_new_position(int keycode, t_game *game, t_player *player)
{
	if (keycode == W || (game->keys.w_pressed && !game->keys.s_pressed))
	{
		game->keys.w_pressed = true;
		player->pos.x += player->rotator.x * MOVE_SPEED;
		player->pos.y += player->rotator.y * MOVE_SPEED;
	}
	if (keycode == S || (game->keys.s_pressed && !game->keys.w_pressed))
	{
		game->keys.s_pressed = true;
		player->pos.x -= player->rotator.x * MOVE_SPEED;
		player->pos.y -= player->rotator.y * MOVE_SPEED;
	}
	if (keycode == A || (game->keys.a_pressed && !game->keys.d_pressed))
	{
		game->keys.a_pressed = true;
		player->pos.x -= player->plane.x * MOVE_SPEED;
		player->pos.y -= player->plane.y * MOVE_SPEED;
	}
	if (keycode == D || (game->keys.d_pressed && !game->keys.a_pressed))
	{
		game->keys.d_pressed = true;
		player->pos.x += player->plane.x * MOVE_SPEED;
		player->pos.y += player->plane.y * MOVE_SPEED;
	}
}

static void	check_player_collision(t_game *game, t_player *player,
		t_vec prev_pos)
{
	int	x;
	int	y;

	// todo split x and y
	if (player->pos.x <= 1.5)
		player->pos.x = 1.5;
	else if (player->pos.x >= (game->map.width - 2.5))
		player->pos.x = (double)(game->map.width - 2.5);
	if (player->pos.y <= 1.5)
		player->pos.y = 1.5;
	else if (player->pos.y >= (game->map.height - 2.5))
		player->pos.y = (double)((game->map.height - 2.5));
	x = (int)floor(player->pos.x);
	y = (int)floor(player->pos.y);
	if (is_collision(game->map.arr, x, y))
	{
		player->pos.x = prev_pos.x;
		player->pos.y = prev_pos.y;
	}
}

void	move_player(int keycode, t_game *game)
{
	t_vec	prev_pos;

	prev_pos = vec_set(game->player.pos.x, game->player.pos.y, 0.0);
	get_new_position(keycode, game, &game->player);
	check_player_collision(game, &game->player, prev_pos);
}
