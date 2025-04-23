/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:24:26 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 10:54:23 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_tile(t_map *map, int x, int y)
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
