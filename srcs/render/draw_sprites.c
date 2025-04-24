/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:51:03 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 10:46:18 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// 1: While raycasting the walls, store the perpendicular distance of each vertical stripe in a 1D ZBuffer
// 2: Calculate the distance of each sprite to the player
// 3: Use this distance to sort the sprites, from furthest away to closest to the camera
// 4: Project the sprite on the camera plane (in 2D): subtract the player position from the sprite position, then multiply the result with the inverse of the 2x2 camera matrix
// 5: Calculate the size of the sprite on the screen (both in x and y direction) by using the perpendicular distance
// 6: Draw the sprites vertical stripe by vertical stripe, don't draw the vertical stripe if the distance is further away than the 1D ZBuffer of the walls of the current stripe
// 7: Draw the vertical stripe pixel by pixel, make sure there's an invisible color or all sprites would be rectangles

void sort_sprite_order(t_map *map)
{
	int i;
	int swapped;
	t_sprite temp;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < map->sprite_count - 1)
		{
			if (map->sprite[i].dist < map->sprite[i + 1].dist && !(map->sprite[i].hidden || map->sprite[i + 1].hidden))
			{
				temp = map->sprite[i];
				map->sprite[i] = map->sprite[i + 1];
				map->sprite[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void calc_sprite_dist(t_game *game)
{
	int i;
	double x;
	double y;

	i = 0;
	while (i < game->map.sprite_count)
	{
		x = square((game->player.pos.x - game->map.sprite[i].pos.x));
		y = square(game->player.pos.y - game->map.sprite[i].pos.y);
		game->map.sprite[i].dist = x + y;
		i++;
	}
}
/**
 * @brief 	This is matrix math to convert from world coordinates → screen space.
		transformY tells you how far away the sprite is (used for depth/perspective).
		transformX tells you where it is horizontally relative to the center of screen.
 * 
 * @param game 
 */
void	transform_to_camspace(t_player *player, t_sprite *sprite)
{
	double det;
	double inv_det;
	
	sprite->relative.x = sprite->pos.x- player->pos.x;
	sprite->relative.y = sprite->pos.y - player->pos.y;
	det = (player->plane.x * player->rotator.y - player->rotator.x * player->plane.y);
	inv_det = 1.0 / det;
	sprite->camspace.x = inv_det * (player->rotator.y * sprite->relative.x - player->rotator.x * sprite->relative.y);
	sprite->camspace.y = inv_det * (-player->plane.y * sprite->relative.x + player->plane.x * sprite->relative.y);
}

void	calc_sprite_size(t_sprite *sprite)
{
	sprite->screenX = (int)((WIDTH / 2) * (1 + sprite->camspace.x / sprite->camspace.y));
	sprite->size = abs((int)(HEIGHT / sprite->camspace.y));
	sprite->size /= sprite->size_adjust;
	sprite->offset = sprite->move / sprite->camspace.y;
}

void calc_draw_heigth(t_sprite *sprite)
{
	sprite->draw_start_y = - sprite->size / 2 + HEIGHT / 2 + sprite->offset;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->size / 2 + HEIGHT / 2 + sprite->offset;
	if (sprite->draw_end_y >= HEIGHT)
		sprite->draw_end_y = HEIGHT - 1;
}

void calc_draw_width(t_sprite *sprite)
{
	sprite->draw_start_x = -sprite->size / 2 + sprite->screenX;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->size / 2 + sprite->screenX;
	if (sprite->draw_end_x >= WIDTH)
		sprite->draw_end_x = WIDTH - 1;
}

void draw_vertical_stripe(t_sprite *sprite, t_game *game, int x, int tex_x)
{
	int y = sprite->draw_start_y;
	while (y < sprite->draw_end_y)
	{
		int d = (y - sprite->offset) * 256 - HEIGHT * 128 + sprite->size * 128;
		int tex_y = ((d * sprite->tex->height) / sprite->size) / 256;

		if (tex_x >= 0 && tex_x < sprite->tex->width && tex_y >= 0 && tex_y < sprite->tex->height)
		{
			t_pixel pxl = {x, y, sprite->tex->buf[sprite->tex->width * tex_y + tex_x]};
			if ((pxl.color & 0x00FFFFFF) != 0)
				put_pixel(&game->mlx.img, pxl);
		}
		y++;
	}
}

void draw_sprite_tex(t_sprite *sprite, t_game *game)
{
	int	x;
	int	tex_x;

	x = sprite->draw_start_x;
	while (x < sprite->draw_end_x)
	{
		tex_x = (int)(256 * (x - (-sprite->size / 2 + sprite->screenX)) * sprite->tex->width / sprite->size) / 256;
		if(sprite->camspace.y > 0 && x > 0 && x < WIDTH && sprite->camspace.y < game->dist_buff[x])
			draw_vertical_stripe(sprite, game, x, tex_x);
		x++;
	}
}

void update_enemy_pointer(t_map *map, t_game *game)
{
	int i;

	i = 0;
	while(i < map->sprite_count)
	{
		if (map->sprite[i].type == ENEMY)
		{
			game->enemy.sprite = &map->sprite[i];
			return;
		}
		i++;
	}
}

void draw_object_sprites(t_game *game)
{
	int i;
	t_sprite *sprite;

	i = 0;
	while (i < game->map.sprite_count)
	{
		sprite = &game->map.sprite[i];
		if (sprite->type == ENEMY)
			update_enemy_pos(game);
		check_collectables(game, sprite);
		transform_to_camspace(&game->player, sprite);
		if (game->map.sprite[i].camspace.y < 0.1 || sprite->hidden || (sprite->type == ENEMY && !game->enemy.alive))
		{
			i++;
			continue;
		}
		calc_sprite_size(sprite);
		calc_draw_heigth(sprite);
		calc_draw_width(sprite);
		draw_sprite_tex(sprite, game);
		i++;
	}
}

void draw_sprites(t_game *game)
{
	calc_sprite_dist(game);
	if (game->map.sprite_count >= 1)
		sort_sprite_order(&game->map);
	update_enemy_pointer(&game->map, game);
	draw_object_sprites(game);
}
