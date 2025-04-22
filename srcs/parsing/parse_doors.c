/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:33:32 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 14:43:41 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_doors_open_pos(t_map *map)
{
	int		i;
	t_pos	pos_open;
	t_door	*doors;
	t_door	*curr;

	i = 0;
	doors = map->doors;
	while (i < map->door_count)
	{
		curr = &map->doors[i];
		pos_open = copy_pos(curr->pos_closed);
		if (is_wall(map->arr, pos_open.x - 1, pos_open.y))
			curr->pos_opened = set_pos(pos_open.x - 1, pos_open.y);
		else if (is_wall(map->arr, pos_open.x + 1, pos_open.y))
			curr->pos_opened = set_pos(pos_open.x + 1, pos_open.y);
		else if (is_wall(map->arr, pos_open.x, pos_open.y - 1))
			curr->pos_opened = set_pos(pos_open.x, pos_open.y - 1);
		else if (is_wall(map->arr, pos_open.x, pos_open.y + 1))
			curr->pos_opened = set_pos(pos_open.x, pos_open.y + 1);
		else
			curr->pos_opened = copy_pos(pos_open);
		i++;
	}
}

static void	init_doors(t_map *map)
{
	int	x;
	int	y;
	int	d;

	y = 0;
	d = 0;
	while (map->arr[y])
	{
		x = 0;
		while (map->arr[y][x])
		{
			if (map->arr[y][x] == DOOR)
			{
				map->doors[d].pos_closed.x = x;
				map->doors[d].pos_closed.y = y;
				map->doors[d].state = CLOSED;
				map->doors[d].tex = &map->D_tex;
				d++;
			}
			x++;
		}
		y++;
	}
}

int	safe_doors(t_map *map)
{
	map->doors = ft_calloc(map->door_count, sizeof(t_door));
	if (!map->doors)
		return (result_failed("ft_calloc", __func__, __FILE__));
	init_doors(map);
	init_doors_open_pos(map);
	return (SUCCESS);
}
