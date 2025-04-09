/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:36:08 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 10:36:36 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_tile(t_game *game, int start_x, int start_y, int color)
{
	t_pixel	pxl;
	int		x;
	int		y;

	pxl.color = color;
	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while (x < TILESIZE)
		{
			pxl.x = start_x + x;
			pxl.y = start_y + y;
			put_pixel(&game->mlx.img, pxl);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	t_pixel	pxl;
	int		x;
	int		y;

	pxl.color = PLAYER_COL;
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			pxl.x = game->player.x + x;
			pxl.y = game->player.y + y;
			put_pixel(&game->mlx.img, pxl);
			x++;
		}
		y++;
	}
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->map.arr[y])
	{
		x = 0;
		while (game->map.arr[y][x])
		{
			color = game->map.floor->col;
			if (game->map.arr[y][x] == WALL)
				color = game->map.ceiling->col;
			draw_tile(game, x * TILESIZE, y * TILESIZE, color);
			x++;
		}
		y++;
	}
	draw_player(game);
	// cast_ray(game->map.arr, 8, 6, 8 * 64, 6 * 64, 1, 1);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img.ptr, 0,
		0);
	return (0);
}
