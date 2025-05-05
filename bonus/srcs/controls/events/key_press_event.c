/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 09:20:04 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	toggle_mouse_hide(t_game *game)
{
	game->keys.h_pressed = true;
	game->mouse.hide = !game->mouse.hide;
	if (game->mouse.hide)
		mlx_mouse_hide(game->mlx.ptr, game->mlx.win);
	else
		mlx_mouse_show(game->mlx.ptr, game->mlx.win);
}

int	key_press_event(int keycode, t_game *game)
{
	if (keycode == E)
		game->keys.e_pressed = true;
	else if (keycode == W)
		game->keys.w_pressed = true;
	else if (keycode == A)
		game->keys.a_pressed = true;
	else if (keycode == S)
		game->keys.s_pressed = true;
	else if (keycode == D)
		game->keys.d_pressed = true;
	else if (keycode == H)
		toggle_mouse_hide(game);
	else if (keycode == R)
		reload_gun(game);
	else if (keycode == ARROW_L)
		game->keys.arrow_left_pressed = true;
	else if (keycode == ARROW_R)
		game->keys.arrow_right_pressed = true;
	else if (keycode == ESC)
		destroy_event(game);
	return (SUCCESS);
}
