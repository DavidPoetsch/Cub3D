/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:06:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 09:17:30 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	mouse_rotation(int x, t_game *game)
{
	static bool	init;
	int			offset_x;
	double		rotation_speed;

	if (!init)
	{
		init = true;
		mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIDTH / 2, HEIGHT / 2);
		return ;
	}
	offset_x = (WIDTH / 2) - x;
	if (abs(offset_x) > 2)
	{
		rotation_speed = offset_x * MOUSE_MOVE_SPEED;
		rotate_player(&game->player, -rotation_speed);
		mlx_mouse_move(game->mlx.ptr, game->mlx.win, WIDTH / 2, HEIGHT / 2);
	}
}

int	mouse_move_event(int x, int y, t_game *game)
{
	(void)y;
	if (game->mouse.hide)
		mouse_rotation(x, game);
	return (SUCCESS);
}
