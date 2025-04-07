/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:08 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/07 17:00:02 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse_hooks(t_game *game)
{
	void	*win;

	if (!game || !game->mlx.ptr || !game->mlx.win)
		return ;
	win = game->mlx.win;
	mlx_hook(win, MotionNotify, PointerMotionMask, &mouse_move_event, game);
	// mlx_hook(fdfh->win, ButtonPress, ButtonPressMask, &handle_mouse_pressed,
	// 	fdfh);
	// mlx_hook(fdfh->win, ButtonRelease, ButtonReleaseMask,
	// 	&handle_mouse_released, fdfh);
}
