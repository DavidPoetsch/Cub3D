/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 16:28:21 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int key_press_event(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;

	if (keycode == W)
		game->player.cam.pos.x -= 0.5;
	if (keycode == A)
		game->player.cam.pos.y -= 0.5;
	if (keycode == S)
		game->player.cam.pos.x += 0.5;
	if (keycode == D)
		game->player.cam.pos.y += 0.5;
	if (keycode == R)
	{
		t_vec new;
		printf("rotate\n");
		new = vec_rot_z(game->player.cam.rotator, 15.0);
		game->player.cam.rotator = new;
	}
	return (SUCCESS);
}
