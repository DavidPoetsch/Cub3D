/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 13:52:55 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int key_press_event(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;

	if (keycode == W)
		game->player.y -= PLAYER_SPEED;
	if (keycode == S)
		game->player.y += PLAYER_SPEED;
	if (keycode == A)
		game->player.x -= PLAYER_SPEED;
	if (keycode == D)
		game->player.x += PLAYER_SPEED;
	return (SUCCESS);
}
