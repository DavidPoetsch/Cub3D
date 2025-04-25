/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:14:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 14:52:54 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	setup_controls(t_game *game)
{
	key_hooks(game);
	mouse_hooks(game);
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
	if (game->keys.arrow_right_pressed)
	{
		rotate_player(&game->player, move_speed);
	}
}
