/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:30:54 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 12:03:07 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_count(t_map *map, int x, int y)
{
	int	count;

	count = 0;
	if (map->arr[y][x] != TORCH)
		return (1);
	else
	{
		if (map->arr[y + 1][x] && map->arr[y + 1][x] == WALL)
			count++;
		if (map->arr[y - 1][x] && map->arr[y - 1][x] == WALL)
			count++;
		if (map->arr[y][x + 1] && map->arr[y][x + 1] == WALL)
			count++;
		if (map->arr[y][x - 1] && map->arr[y][x - 1] == WALL)
			count++;
		return (count);
	}
}

static int	sprite_loop(t_map *map, t_game *game, int x, int y)
{
	int	i;
	int	res;
	int	count;

	i = 0;
	res = SUCCESS;
	count = get_count(map, x, y);
	while (i < count && res == SUCCESS)
	{
		res = init_sprite(map, x, y, &map->sprite[map->curr_sprites]);
		if (map->sprite[map->curr_sprites].type == ENEMY)
			init_enemy(game, &map->sprite[map->curr_sprites]);
		map->curr_sprites++;
		i++;
	}
	if (map->sprite[map->curr_sprites - 1].type == TORCH)
		adjust_placement(map, count, x, y);
	return (res);
}

static int	get_sprites(t_map *map, t_game *game)
{
	int	x;
	int	y;
	int	res;

	y = 0;
	res = SUCCESS;
	while (map->arr[y] && res == SUCCESS)
	{
		x = 0;
		while (map->arr[y][x] && res == SUCCESS)
		{
			if (is_sprite(map->arr[y][x]))
				res = sprite_loop(map, game, x, y);
			x++;
		}
		y++;
	}
	return (res);
}

static int	parse_sprites(t_map *map, t_game *game)
{
	int	res;

	res = SUCCESS;
	map->sprite_count = get_sprite_count(map);
	map->curr_sprites = 0;
	if (map->sprite_count > 0)
	{
		map->sprite = ft_calloc(map->sprite_count, sizeof(t_sprite));
		if (!map->sprite)
			return (result_failed("ft_calloc", __func__, __FILE__));
		res = get_sprites(map, game);
	}
	return (res);
}

int parse_sprites_and_doors(t_game *game)
{
	int res;

	res = SUCCESS;
	if (res == SUCCESS && game->map.door_count > 0)
		res = safe_doors(&game->map);
	if (res == SUCCESS)
		res = parse_sprites(&game->map, game);
	return (res);
}
