/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:14:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/16 09:57:22 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	controls(t_game *game)
{
	key_hooks(game);
	mouse_hooks(game);
}

void	check_controls(t_game *game)
{
	move_player(game);
	if (game->keys.arrow_left_pressed)
	{
		rotate_player(&game->player, ROTATION_SPEED);
	}
	if (game->keys.arrow_right_pressed)
	{
		rotate_player(&game->player, -ROTATION_SPEED);
	}
}
