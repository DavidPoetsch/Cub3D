/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:05 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 15:00:05 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_player(char c)
{
	return(c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

int	check_player_start(t_map *map, t_player *player)
{
	int	x;
	int	y;
	int player_found;

	y = 0;
	player_found = ERROR;
	while(map->arr[y])
	{
		x = 0;
		while(map->arr[y][x])
		{
			if (is_player(map->arr[y][x]))
			{
				player->x = x * TILESIZE + TILESIZE / 2 - PLAYER_SIZE / 2;
				map->start_x = x;
				player->y = y * TILESIZE + TILESIZE / 2 - PLAYER_SIZE / 2;
				map->start_y = y;
				if (player_found == SUCCESS)
					return (ERROR);
				player_found = SUCCESS;
			}
			x++;
		}
		y++;
	}
	return (player_found);
}
