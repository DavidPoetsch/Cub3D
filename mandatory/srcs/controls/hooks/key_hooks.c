/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:24:59 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/07 16:59:33 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_hooks(t_game *game)
{
	void	*win;

	if (!game || !game->mlx.ptr || !game->mlx.win)
		return ;
	win = game->mlx.win;
	mlx_hook(win, KeyPress, KeyPressMask, &key_press_event, game);
	mlx_hook(win, KeyRelease, KeyReleaseMask, &key_release_event, game);
	mlx_hook(win, DestroyNotify, KeyPressMask, &destroy_event, game);
}
