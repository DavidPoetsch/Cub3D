/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pistol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:21:22 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 09:08:48 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pistol(t_game *game)
{
	t_pos	pos;

	if (WIDTH < 1200)
		pos.x = (WIDTH / 2);
	else
		pos.x = (WIDTH / 5) * 3;
	if (game->player.pistol_animation > 0.0)
	{
		game->player.pistol_animation -= game->delta_sec;
		pos.y = HEIGHT - game->img_pistol_shot.height;
		move_img_buf(&game->img_pistol_shot, &game->mlx.img, pos, false);
	}
	else
	{
		pos.y = HEIGHT - game->img_pistol.height;
		move_img_buf(&game->img_pistol, &game->mlx.img, pos, false);
	}
}
