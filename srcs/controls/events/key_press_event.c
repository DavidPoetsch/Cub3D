/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/08 16:44:02 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int key_press_event(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;

	if (keycode == W)
		game->player.cam.pos.x--;
	if (keycode == A)
		game->player.cam.pos.y--;
	if (keycode == S)
		game->player.cam.pos.x++;
	if (keycode == D)
		game->player.cam.pos.y++;
	game->update = true;
	return (SUCCESS);
}
