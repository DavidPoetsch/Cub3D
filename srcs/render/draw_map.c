/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/04/09 11:56:57 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 14:11:45 by lstefane         ###   ########.fr       */
=======
/*   Created: 2025/04/14 10:36:08 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 10:40:47 by dpotsch          ###   ########.fr       */
>>>>>>> c813ca5b0764b47986704522f2cab9235f2f0e7b
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
static void put_pixel(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		game->mlx.buf[(y * game->mlx.line_pixels) + x] = color;
}

void draw_tile(t_game *game, int start_x, int start_y, int color)
{
	int x;
	int y;

	y = 0;
	while (y < TILESIZE)
	{
		x = 0;
		while(x < TILESIZE)
		{
			put_pixel(game, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			put_pixel(game, game->player.x + x, game->player.y + y, PLAYER_COL);
			x++;
		}
		y++;
	}
}

int draw_map(t_game *game)
{
	int x;
	int y;
	int color;

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
=======
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
>>>>>>> c813ca5b0764b47986704522f2cab9235f2f0e7b
			x++;
		}
		y++;
	}
<<<<<<< HEAD
	draw_player(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
=======
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
>>>>>>> c813ca5b0764b47986704522f2cab9235f2f0e7b
	return (0);
}
