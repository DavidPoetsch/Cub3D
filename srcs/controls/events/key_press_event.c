/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 09:54:47 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press_event(int keycode, t_game *game)
{
	// printf("KEY: %d\n", keycode);
	if (keycode == E)
		game->keys.e_pressed = true;
	if (keycode == W)
		game->keys.w_pressed = true;
	if (keycode == A)
		game->keys.a_pressed = true;
	if (keycode == S)
		game->keys.s_pressed = true;
	if (keycode == D)
		game->keys.d_pressed = true;
	if (keycode == ARROW_L)
		game->keys.arrow_left_pressed = true;
	if (keycode == ARROW_R)
		game->keys.arrow_right_pressed = true;
	if (keycode == ESC)
		free_all_exit(game);
	return (SUCCESS);
}
