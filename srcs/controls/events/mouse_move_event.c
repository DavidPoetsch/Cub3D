/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:06:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 12:20:45 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move_event(int x, int y, t_game *game)
{
	static bool	init;
	t_vec		new;
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
		rotation_speed = offset_x * get_delta_seconds() * 10;
		new = vec_rot_z(game->player.cam.rotator, rotation_speed);
		game->player.cam.rotator = new;
		new = vec_rot_z(game->render.plane, rotation_speed);
		game->render.plane = new;
		mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIDTH / 2, HEIGHT / 2);
	}
	return (SUCCESS);
}
