/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 13:50:45 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player_pos(t_game *game)
{
	t_pixel	pos;
	t_pixel	pos_txt;

	pos_txt.x = 38;
	pos_txt.y = 40;
	pos_txt.color = 0x000000;
	pos = new_pxl(pos_txt.x + 20, pos_txt.y, pos_txt.color);
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_string(game, pos_txt, "x: ");
	put_nbr(game, pos, game->player.pos.x);
	pos.y += 20;
	pos_txt.y += 20;
	put_string(game, pos_txt, "y: ");
	put_nbr(game, pos, game->player.pos.y);
}

void	draw_fps(t_game *game)
{
	t_pixel	pos;
	t_pixel	pos_txt;

	pos_txt.x = 20;
	pos_txt.y = 20;
	pos_txt.color = 0x000000;
	pos = new_pxl(pos_txt.x + 40, pos_txt.y, pos_txt.color);
	mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
	put_string(game, pos_txt, "FPS: ");
	put_nbr(game, pos, 1.0 / game->delta_sec);
}

void	draw_crosshair(t_img *img, t_pixel pxl, int size)
{
	int	i;
	int	j;
	int	y_start;

	i = 0;
	y_start = pxl.y;
	while (i < size)
	{
		j = 0;
		pxl.y = y_start;
		while (j < size)
		{
			if (i >= 3 && i <= 6)
				put_pixel(img, pxl);
			if (j >= 3 && j <= 6)
				put_pixel(img, pxl);
			pxl.y++;
			j++;
		}
		pxl.x++;
		i++;
	}
}

void	draw_aimbot(t_game *game)
{
	t_pixel	pos;

	pos.x = WIDTH / 2 - 5;
	pos.y = HEIGHT / 2 - 5;
	pos.color = PLAYER_COL;
	draw_crosshair(&game->mlx.img, pos, 10);
}
