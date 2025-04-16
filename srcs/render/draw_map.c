/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:56:57 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/16 15:18:45 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_tile_color(t_game *game, int x, int y)
{
	int	color;

	color = game->map.floor->col;
	if (x >= 0 && y >= 0 && x < game->map.width && y < game->map.height)
	{
		if (game->map.arr[y][x] == WALL)
			color = game->map.ceiling->col;
		else if (game->map.arr[y][x] == DOOR)
			color = MAP_DOOR_COLOR;
	}
	return (color);
}

static void	draw_player(t_game *game, int x_offset, int y_offset)
{
	t_pixel	pxl;
	t_pixel	pxl_center;
	int		player_size;
	int		x;
	int		y;

	pxl_center.x = (MAP_SIZE / 2) * TILESIZE + x_offset;
	pxl_center.y = (MAP_SIZE / 2) * TILESIZE + y_offset;
	player_size = (PLAYER_SIZE / 2);
	pxl.color = PLAYER_COL;
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			pxl.x = pxl_center.x + x - player_size;
			pxl.y = pxl_center.y + y - player_size;
			put_pixel(&game->mlx.img, pxl);
			x++;
		}
		y++;
	}
	pxl_center.color = MAP_DOOR_COLOR;
	draw_line(game, pxl_center, game->player.rotator, MAP_SIZE / 2 * TILESIZE);
}

static void	draw_map_background(t_game *game, int x_offset, int y_offset)
{
	t_pixel	pxl;
	int		size;

	pxl.color = MAP_BACKGROUND;
	pxl.x = x_offset - MAP_PADDING;
	pxl.y = y_offset - MAP_PADDING;
	size = (MAP_SIZE * TILESIZE) + 2 * MAP_PADDING;
	draw_area(game, pxl, size);
}

void	draw_tiles(t_game *game, int x_offset, int y_offset)
{
	t_pixel	pxl;
	int		i;
	int		j;
	int		x;
	int		y;

	x = round(game->player.pos.x) - MAP_SIZE / 2;
	i = 0;
	while (i < MAP_SIZE)
	{
		y = round(game->player.pos.y) - MAP_SIZE / 2;
		j = 0;
		while (j < MAP_SIZE)
		{
			pxl.x = i * TILESIZE + x_offset;
			pxl.y = j * TILESIZE + y_offset;
			pxl.color = get_tile_color(game, x, y);
			draw_area(game, pxl, TILESIZE);
			y += 1;
			j++;
		}
		x += 1;
		i++;
	}
}

int	draw_map(t_game *game)
{
	int	x_offset;
	int	y_offset;

	x_offset = WIDTH - (MAP_SIZE * TILESIZE) - MAP_PADDING - 2;
	y_offset = MAP_PADDING + 2;
	draw_map_background(game, x_offset, y_offset);
	draw_tiles(game, x_offset, y_offset);
	draw_player(game, x_offset, y_offset);
	return (0);
}
