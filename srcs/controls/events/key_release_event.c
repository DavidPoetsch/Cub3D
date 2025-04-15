/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 16:26:18 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int key_release_event(int keycode, t_game *game)
{
	if (keycode == E)
		game->keys.e_pressed = false;
	if (keycode == W)
		game->keys.w_pressed = false;
	if (keycode == A)
		game->keys.a_pressed = false;
	if (keycode == S)
		game->keys.s_pressed = false;
	if (keycode == D)
		game->keys.d_pressed = false;
	return (SUCCESS);
}
