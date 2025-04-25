/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pistol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:21:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 12:36:26 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pistol(t_game *game)
{
	t_pos	pos;

	if (!game->img_pistol || !game->img_shot)
		return ;
	if (WIDTH < 1200)
		pos.x = game->mlx.center.x;
	else
		pos.x = (WIDTH / 5) * 3;
	if (game->player.pistol_animation > 0.0)
	{
		game->player.pistol_animation -= game->delta_sec;
		pos.y = HEIGHT - game->img_shot->height;
		move_img_buf(game->img_shot, &game->mlx.img, pos, false);
	}
	else
	{
		pos.y = HEIGHT - game->img_pistol->height;
		move_img_buf(game->img_pistol, &game->mlx.img, pos, false);
	}
}
