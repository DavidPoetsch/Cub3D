/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 14:38:21 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_fps(t_game *game)
{
	t_pixel	pos;

	pos.x = 10;
	pos.y = 20;
	pos.color = 0x000000;
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_nbr(game, pos, 1.0 / game->render.delta_seconds);
}
