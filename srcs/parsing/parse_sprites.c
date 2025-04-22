/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:54 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 08:57:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

bool is_sprite(char tile)
{
	if (tile == WALL)
		return false;
	if (tile == DOOR)
		return false;
	if (tile == OPEN)
		return false;
	return true;
}

int check_tile(t_map *map, int x, int y)
{
	int count;

	count = 0;
	if(map->arr[y][x] == ENEMY || map->arr[y][x] == AMMO)
		return 1;
	if (map->arr[y][x] == TORCH)
	{
		if(map->arr[y + 1][x] && map->arr[y + 1][x] == WALL)
			count++;
		if(map->arr[y - 1][x] && map->arr[y - 1][x] == WALL)
			count++;
		if(map->arr[y][x + 1] && map->arr[y][x + 1] == WALL)
			count++;
		if(map->arr[y][x - 1] && map->arr[y][x - 1] == WALL)
			count++;
	}
	return (count);
}

int get_sprite_count(t_map *map)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	while(map->arr[y])
	{
		x = 0;
		while(map->arr[y][x])
		{
			if (is_sprite(map->arr[y][x]))
				count += check_tile(map, x, y);
			x++;
		}
		y++;
	}
	return (count);
}

int	get_sprite_size(char tile)
{
	if (tile == AMMO || tile == TORCH)
		return 2;
	return 1;
}

int get_tex_count(char **paths)
{
	int count;

	count = 0;
	while(paths && paths[count])
		count++;
	return count;
}

int get_sprite_textures(char *tile, t_sprite * sprite, t_map *map)
{
	int res;
	char **paths;

	paths = get_paths(tile, map->textures);
	if (!paths)
		return (result_error("no paths for texture were found"));
	else
		sprite->tex_count = get_tex_count(paths);
	if (sprite->tex_count > 0)
	{
		sprite->texs = ft_calloc(sprite->tex_count, sizeof(t_textures));
		if(!sprite->texs)
			return (result_failed("ft_calloc", __func__, __FILE__));
	}
}
int init_sprite(t_map *map, int x, int y, t_sprite *sprite)
{
	int res;
	if (map->arr[y][x] == WALL || map->arr[y][x] )
		return SUCCESS;
	
	sprite->pos.x = x;
	sprite->pos.y = y;

	sprite->type = OBJECT;
	if (map->arr[y][x] == AMMO)
		sprite->type = COLLECT;

	sprite->size_adjust = get_size_adjustment(map->arr[y][x]);
	res = get_sprite_texture(map->arr[y][x], sprite, map);


}


int get_sprites(t_map *map)
{
	int x;
	int y;
	int i;
	int res;

	y = 0;
	res = SUCCESS;
	while(map->arr[y])
	{
		x = 0;
		while(map->arr[y][x])
		{
			res = init_sprite(map, x, y, &map->sprite[map->sprite_count - 1]);
			if (res != SUCCESS)
				break;
			x++;
		}
		y++;
	}
	return (res);
}


int parse_sprites(t_map *map)
{
	int res;

	res = SUCCESS;
	map->sprite_count = get_sprite_count(map);
	printf("SPRITE COUNT: %d\n", map->sprite_count);
	if (map->sprite_count > 0)
	{
		map->sprite = ft_calloc(map->sprite_count, sizeof(t_sprite));
		if (!map->sprite)
			return (ERROR);
		res = get_sprites(map);
	}
	return (res);
}