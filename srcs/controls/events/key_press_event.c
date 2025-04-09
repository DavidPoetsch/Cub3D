/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 10:28:29 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press_event(int keycode, t_game *game)
{
	t_vec new;

	(void)keycode;
	(void)game;
	if (keycode == W)
	{
		game->player.cam.pos.x += game->player.cam.rotator.x * 2;
		game->player.cam.pos.y += game->player.cam.rotator.y * 2;
	}
	if (keycode == S)
	{
		game->player.cam.pos.x -= game->player.cam.rotator.x * 2;
		game->player.cam.pos.y -= game->player.cam.rotator.y * 2;
	}
	if (keycode == A)
	{
		game->player.cam.pos.x -= game->render.plane.x * 2;
		game->player.cam.pos.y -= game->render.plane.y * 2;
	}
	if (keycode == D)
	{
		game->player.cam.pos.x += game->render.plane.x * 2;
		game->player.cam.pos.y += game->render.plane.y * 2;
	}
	if (keycode == ARROW_L)
	{
		new = vec_rot_z(game->player.cam.rotator, 15.0);
		game->player.cam.rotator = new;
		new = vec_rot_z(game->render.plane, 15.0);
		game->render.plane = new;
	}
	if (keycode == ARROW_R)
	{
		new = vec_rot_z(game->player.cam.rotator, -15.0);
		game->player.cam.rotator = new;
		new = vec_rot_z(game->render.plane, -15.0);
		game->render.plane = new;
	}
	return (SUCCESS);
}
