/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:56:57 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 16:18:54 by dpotsch          ###   ########.fr       */
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
		else if (game->map.arr[y][x] == ENEMY)
			color = 0x0000FF;
	}
	return (color);
}

static void	draw_minimap_ray(t_game *game)
{
	t_pixel	pxl_center;
	double	ray_len;

	pxl_center.x = game->minimap.size / 2;
	pxl_center.y = game->minimap.size / 2;
	pxl_center.color = MAP_DOOR_COLOR;
	ray_len = game->minimap.mini_map_ray_len * MAP_TILE_SIZE;
	draw_line(&game->minimap.img, pxl_center, game->player.rotator, ray_len);
}

static void	draw_tiles(t_game *game)
{
	t_pixel	pxl;
	t_pos	minimap;
	int		x;
	int		y;

	x = floor(game->player.pos.x) - MAP_TILES / 2;
	minimap.x = 0;
	while (minimap.x < MAP_TILES)
	{
		pxl.x = minimap.x * MAP_TILE_SIZE + MAP_PADDING + 1;
		minimap.y = 0;
		y = floor(game->player.pos.y) - MAP_TILES / 2;
		while (minimap.y < MAP_TILES)
		{
			pxl.y = minimap.y * MAP_TILE_SIZE + MAP_PADDING + 1;
			pxl.color = get_tile_color(game, x, y);
			if (minimap.x == MAP_TILES / 2 && minimap.y == MAP_TILES / 2)
				pxl.color = PLAYER_COL;
			draw_area(&game->minimap.img, pxl, MAP_TILE_SIZE - 2);
			minimap.y++;
			y++;
		}
		minimap.x++;
		x++;
	}
}

int	draw_map(t_game *game)
{
	t_pixel	pxl;

	game->minimap.offset.x = WIDTH - game->minimap.size - 10;
	game->minimap.offset.y = 10;
	pxl = new_pxl(0, 0, MAP_BACKGROUND);
	draw_area(&game->minimap.img, pxl, game->minimap.size);
	draw_tiles(game);
	draw_minimap_ray(game);
	move_img_buf(&game->minimap.img, &game->mlx.img, game->minimap.offset,
		true);
	return (0);
}
