/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hitmarker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:21:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 10:30:50 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_thick_pixel(t_img *img, int x, int y, int thickness)
{
	int dx;
	int dy;
	t_pixel pxl;

	dy = -thickness / 2;
	while (dy <= thickness)
	{
		dx = -thickness / 2;
		while (dx <= thickness)
		{
			pxl.x = x + dx;
			pxl.y = y + dy;
			pxl.color = 0xFF2222;
			if ((pxl.x <= WIDTH / 2 - 7 || pxl.x >= WIDTH / 2 + 7) && (pxl.y <= HEIGHT / 2 - 7 || pxl.y >= HEIGHT / 2 + 7))
				put_pixel(img, pxl);
			dx++;
		}
		dy++;
	}
}

void draw_diagonal(t_img *img, int i, int x_dir, int y_dir)
{
	int line;
	int x;
	int y;

	line = 0;
	x = WIDTH / 2 - 1;
	y = HEIGHT / 2 - 1;
	x = x + (i * x_dir);
	y = y + (i * y_dir);
	draw_thick_pixel(img, x, y, 1);
	line++;
}

void print_hit_marker(t_img *img, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		draw_diagonal(img, i, -1, -1); //nw
		draw_diagonal(img, i, 1, -1); //ne
		draw_diagonal(img, i, -1, 1); //sw
		draw_diagonal(img, i, 1, 1); //se
		i++;
	}
}

void draw_hitmarker(t_game *game)
{
	if (game->enemy.hit)
	{
		game->enemy.hit_time -= game->delta_sec;
		if (game->enemy.hit_time <= 0)
		{
			game->enemy.hit_time = HITMARKER;
			game->enemy.hit = false;
		}
	}
	if (!game->enemy.hit)
		return;
	print_hit_marker(&game->mlx.img, 20);
}
