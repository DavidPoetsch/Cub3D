/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:51:03 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:54:36 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sort_sprite_order(t_map *map)
{
	int			i;
	int			swapped;
	t_sprite	temp;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < map->sprite_count - 1)
		{
			if (map->sprite[i].dist < map->sprite[i + 1].dist
				&& !(map->sprite[i].hidden || map->sprite[i + 1].hidden))
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

static void	calc_sprite_dist(t_game *game)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	while (i < game->map.sprite_count)
	{
		x = square((game->player.pos.x - game->map.sprite[i].pos.x));
		y = square(game->player.pos.y - game->map.sprite[i].pos.y);
		game->map.sprite[i].dist = x + y;
		i++;
	}
}

static void	update_enemy_pointer(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (i < map->sprite_count)
	{
		if (map->sprite[i].type == ENEMY)
		{
			game->enemy.sprite = &map->sprite[i];
			return ;
		}
		i++;
	}
}

void	draw_sprites(t_game *game)
{
	calc_sprite_dist(game);
	if (game->map.sprite_count >= 1)
		sort_sprite_order(&game->map);
	update_enemy_pointer(&game->map, game);
	draw_sprites_objects(game);
}
