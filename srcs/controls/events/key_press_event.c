/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 14:28:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifndef MOVE_SPEED
# define MOVE_SPEED 0.25
#endif

void move_player(int keycode, t_player *player)
{
	if (keycode == W)
	{
		player->pos.x += player->rotator.x * MOVE_SPEED;
		player->pos.y += player->rotator.y * MOVE_SPEED;
	}
	if (keycode == S)
	{
		player->pos.x -= player->rotator.x * MOVE_SPEED;
		player->pos.y -= player->rotator.y * MOVE_SPEED;
	}
	if (keycode == A)
	{
		player->pos.x -= player->plane.x * MOVE_SPEED;
		player->pos.y -= player->plane.y * MOVE_SPEED;
	}
	if (keycode == D)
	{
		player->pos.x += player->plane.x * MOVE_SPEED;
		player->pos.y += player->plane.y * MOVE_SPEED;
	}
}

int	key_press_event(int keycode, t_game *game)
{
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		move_player(keycode, &game->player);
	if (keycode == ARROW_L)
	{
		rotate_player(&game->player, 15);
	}
	if (keycode == ARROW_R)
	{
		rotate_player(&game->player, -15);
	}
	return (SUCCESS);
}
