/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:33:32 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/23 10:29:06 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_doors(t_map *map)
{
	int	x;
	int	y;
	int	d;

	y = 0;
	d = 0;
	while(map->arr[y])
	{
		x = 0;
		while(map->arr[y][x])
		{
			if (map->arr[y][x] == DOOR)
			{
				map->doors[d].pos.x = x;
				map->doors[d].pos.y = y;
				map->doors[d].state = CLOSED;
				map->doors[d].tex = map->D_tex;
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
		return result_failed("ft_calloc", __func__, __FILE__);
	init_doors(map);
	return (SUCCESS);
}
