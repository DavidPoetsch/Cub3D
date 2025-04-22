/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:56 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 16:33:16 by dpotsch          ###   ########.fr       */
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

void	draw_crosshair(t_img *img, int size)
{
	t_pixel	pxl;
	int		i;
	int		j;
	int		y_start;

	pxl = new_pxl(WIDTH / 2 - size, HEIGHT / 2 - size, PLAYER_COL);
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

void	draw_time_til_restart(t_game *game)
{
	t_pixel	pxl;
	float	remaining_sec;
	size_t	ms_curr;

	ms_curr = get_time_ms();
	if (game->state == GAME_RESTART)
	{
		pxl.x = game->mlx.center.x + 10;
		pxl.y = game->mlx.center.y + 10;
		pxl.color = 0xFFFFFF;
		mlx_set_font(game->mlx.ptr, game->mlx.win, FONT2);
		remaining_sec = (game->restart_time - ms_curr) / 1000.0;
		if (remaining_sec >= 0.0 && remaining_sec <= (float)RESTART_TIME)
			put_nbr(game, pxl, remaining_sec);
	}
}

void	draw_ammo(t_game *game)
{
	int		i;
	t_pixel	pxl;

	pxl.color = 0;
	pxl.x = 10;
	pxl.y = HEIGHT - 20;
	i = 0;
	while (i < game->player.ammo)
	{
		draw_area(&game->mlx.img, pxl, 10);
		pxl.x += 15;
		i++;
	}
}
