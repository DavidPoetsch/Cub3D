/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 09:18:36 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_release_event(int keycode, t_game *game)
{
	if (keycode == E)
		game->keys.e_pressed = false;
	else if (keycode == W)
		game->keys.w_pressed = false;
	else if (keycode == A)
		game->keys.a_pressed = false;
	else if (keycode == S)
		game->keys.s_pressed = false;
	else if (keycode == D)
		game->keys.d_pressed = false;
	else if (keycode == H)
		game->keys.h_pressed = false;
	else if (keycode == ARROW_L)
		game->keys.arrow_left_pressed = false;
	else if (keycode == ARROW_R)
		game->keys.arrow_right_pressed = false;
	return (SUCCESS);
}
