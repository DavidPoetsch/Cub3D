/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:14:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 10:18:09 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	setup_controls(t_game *game)
{
	key_hooks(game);
	mouse_hooks(game);
	if (game->mlx.ptr != NULL && game->mlx.win != NULL && game->mouse.hide)
		mlx_mouse_hide(game->mlx.ptr, game->mlx.win);
}

void	check_controls(t_game *game)
{
	double	move_speed;

	move_player(game);
	move_speed = game->delta_sec * ROTATION_SPEED;
	if (game->keys.arrow_left_pressed)
	{
		rotate_player(&game->player, -move_speed);
	}
	else if (game->keys.arrow_right_pressed)
	{
		rotate_player(&game->player, move_speed);
	}
}
