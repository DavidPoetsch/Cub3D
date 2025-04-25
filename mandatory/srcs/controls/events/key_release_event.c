/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 16:08:26 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_release_event(int keycode, t_game *game)
{
	if (keycode == W)
		game->keys.w_pressed = false;
	if (keycode == A)
		game->keys.a_pressed = false;
	if (keycode == S)
		game->keys.s_pressed = false;
	if (keycode == D)
		game->keys.d_pressed = false;
	if (keycode == ARROW_L)
		game->keys.arrow_left_pressed = false;
	if (keycode == ARROW_R)
		game->keys.arrow_right_pressed = false;
	return (SUCCESS);
}
