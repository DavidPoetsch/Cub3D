/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 14:00:31 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press_event(int keycode, t_game *game)
{
	if (keycode == W)
	{
		game->player.pos.x += game->player.rotator.x * 2;
		game->player.pos.y += game->player.rotator.y * 2;
	}
	if (keycode == S)
	{
		game->player.pos.x -= game->player.rotator.x * 2;
		game->player.pos.y -= game->player.rotator.y * 2;
	}
	if (keycode == A)
	{
		game->player.pos.x -= game->player.plane.x * 2;
		game->player.pos.y -= game->player.plane.y * 2;
	}
	if (keycode == D)
	{
		game->player.pos.x += game->player.plane.x * 2;
		game->player.pos.y += game->player.plane.y * 2;
	}
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
