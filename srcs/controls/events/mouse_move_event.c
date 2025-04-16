/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:06:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 10:54:30 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move_event(int x, int y, t_game *game)
{
	static bool	init;
	int			offset_x;
	double		rotation_speed;

	(void)y;
	if (!init)
	{
		init = true;
		mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIDTH / 2, HEIGHT / 2);
		return (SUCCESS);
	}
	offset_x = (WIDTH / 2) - x;
	if (abs(offset_x) > 2)
	{
		rotation_speed = offset_x * get_delta_seconds() * MOUSE_MOVE_SPEED;
		rotate_player(&game->player, rotation_speed);
		mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIDTH / 2, HEIGHT / 2);
	}
	return (SUCCESS);
}
