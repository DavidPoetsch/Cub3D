/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 15:55:40 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifndef MOVE_SPEED
# define MOVE_SPEED 0.25
#endif

void move_player(int keycode, t_player *player, t_game *game)
{
	if (keycode == W)
	{
		game->keys.w_pressed = true;
		player->pos.x += player->rotator.x * MOVE_SPEED;
		player->pos.y += player->rotator.y * MOVE_SPEED;
	}
	if (keycode == S)
	{
		game->keys.s_pressed = true;
		player->pos.x -= player->rotator.x * MOVE_SPEED;
		player->pos.y -= player->rotator.y * MOVE_SPEED;
	}
	if (keycode == A)
	{
		game->keys.a_pressed = true;
		player->pos.x -= player->plane.x * MOVE_SPEED;
		player->pos.y -= player->plane.y * MOVE_SPEED;
	}
	if (keycode == D)
	{
		game->keys.d_pressed = true;
		player->pos.x += player->plane.x * MOVE_SPEED;
		player->pos.y += player->plane.y * MOVE_SPEED;
	}
}

int	key_press_event(int keycode, t_game *game)
{
	printf("KEY: %d\n", keycode);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		move_player(keycode, &game->player, game);
	if (keycode == ARROW_L)
	{
		rotate_player(&game->player, 15);
	}
	if (keycode == ARROW_R)
	{
		rotate_player(&game->player, -15);
	}
	if (keycode == E)
		game->keys.e_pressed = (true);
	return (SUCCESS);
}
