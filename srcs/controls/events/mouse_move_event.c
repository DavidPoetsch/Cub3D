/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:06:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 12:31:56 by lstefane         ###   ########.fr       */
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
		rotation_speed = offset_x * get_delta_seconds() * 10;
		rotate_player(&game->player, rotation_speed);
		mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIDTH / 2, HEIGHT / 2);
	}
	return (SUCCESS);
}
