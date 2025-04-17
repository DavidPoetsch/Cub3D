/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:08 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 15:19:11 by lstefane         ###   ########.fr       */
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
	mlx_hook(win, ButtonPress, ButtonPressMask, &mouse_press_event, game);
	mlx_hook(win, ButtonRelease, ButtonReleaseMask, &mouse_release_event, game);
}
