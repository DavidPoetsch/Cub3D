/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:56:57 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 10:07:51 by dpotsch          ###   ########.fr       */
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

static void	draw_map_background(t_game *game)
{
	t_pixel	pxl;

	pxl = new_pxl(0, 0, MAP_BACKGROUND);
	draw_area(&game->minimap.img, pxl, MAP_SIZE);
}

void	draw_tiles(t_game *game)
{
	int tile_size;
	t_pixel	pxl;
	int		x;
	int		y;
	int		x_mm;
	int		y_mm;

	tile_size = floor(MAP_SIZE / MAP_TILES);
	x = floor(game->player.pos.x) - MAP_TILES / 2;
	x_mm = 0;
	while (x_mm < MAP_TILES)
	{
		pxl.x = x_mm * tile_size;
		y_mm = 0;
		y = floor(game->player.pos.y) - MAP_TILES / 2;
		while(y_mm < MAP_TILES)
		{
			pxl.y = y_mm * tile_size;
			pxl.color = get_tile_color(game, x, y);
			if (x_mm == MAP_TILES / 2 && y_mm == MAP_TILES / 2)
				pxl.color = PLAYER_COL;
			draw_area(&game->minimap.img, pxl, MAP_TILE_SIZE);
			y_mm ++;
			y++;
		}
		x_mm++;
		x++;
	}
}

int	draw_map(t_game *game)
{
	int tiles;

	game->minimap.x_offset = WIDTH - MAP_SIZE - 10;
	game->minimap.y_offset = 10;
	// map_size = MAP_SIZE - MAP_PADDING * 2;
	tiles = MAP_SIZE / 9;
	draw_map_background(game);
	draw_tiles(game);
	// draw_player(game, game->minimap.tilesize);
	return (0);
}
