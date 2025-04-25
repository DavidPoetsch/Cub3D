/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites_adjustment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:13:51 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 14:41:58 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_hits(t_wall_hit *hit, int x, int y, char **map)
{
	if (!hit || !map)
		return ;
	if (map[y - 1][x] && map[y - 1][x] == WALL)
		hit->n = 1;
	if (map[y + 1][x] && map[y + 1][x] == WALL)
		hit->s = 1;
	if (map[y][x + 1] && map[y][x + 1] == WALL)
		hit->e = 1;
	if (map[y][x - 1] && map[y][x - 1] == WALL)
		hit->w = 1;
}

static void	change_placement(t_sprite *sprite, t_wall_hit *hit)
{
	if (hit->n)
	{
		sprite->pos.y -= 0.45;
		hit->n = 0;
		return ;
	}
	if (hit->e)
	{
		sprite->pos.x += 0.45;
		hit->e = 0;
		return ;
	}
	if (hit->s)
	{
		sprite->pos.y += 0.45;
		hit->s = 0;
		return ;
	}
	if (hit->w)
	{
		sprite->pos.x -= 0.45;
		hit->w = 0;
		return ;
	}
}

void	adjust_placement(t_map *map, int count, int x, int y)
{
	t_wall_hit	hit;
	int			i;

	hit.n = 0;
	hit.w = 0;
	hit.s = 0;
	hit.e = 0;
	i = 1;
	check_hits(&hit, x, y, map->arr);
	while (i <= count)
	{
		change_placement(&map->sprite[map->curr_sprites - i], &hit);
		i++;
	}
}
