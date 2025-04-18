/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:54 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 16:48:22 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_tile(t_map *map, int x, int y)
{
	int count;

	count = 0;
	if(map->arr[y][x] == OPEN || map->arr[y][x] == WALL || map->arr[y][x] == DOOR)
		return 0;
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
			count += check_tile(map, x, y);
			x++;
		}
		y++;
	}
	return (count);
}

int parse_sprites(t_map *map)
{
	int res;

	res = SUCCESS;
	map->sprite_count = get_sprite_count(map);
	printf("SPRITE COUNT: %d\n", map->sprite_count);
	return (res);
}