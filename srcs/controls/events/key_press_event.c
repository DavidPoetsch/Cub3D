/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:57:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 16:58:43 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press_event(int keycode, t_game *game)
{
	printf("KEY: %d\n", keycode);
	if (keycode == ESC)
		free_all_exit(game);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		move_player(keycode, game);
	if (keycode == ARROW_L)
	{
		rotate_player(&game->player, 15);
	}
	if (keycode == ARROW_R)
	{
		rotate_player(&game->player, -15);
	}
	if (keycode == E)
		game->keys.e_pressed = (true);
	return (SUCCESS);
}
