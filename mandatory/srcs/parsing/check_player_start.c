/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:05 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 16:23:23 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player_start(t_map *map, t_player *player, int x, int y)
{
	player->dir = map->arr[y][x];
	player->start_x = x;
	player->start_y = y;
	map->start_x = x;
	map->start_y = y;
}

int	check_player_start(t_map *map, t_player *player)
{
	int	x;
	int	y;
	int	player_found;

	y = 0;
	player_found = ERROR;
	while (map->arr[y])
	{
		x = 0;
		while (map->arr[y][x])
		{
			if (is_player(map->arr[y][x]))
			{
				init_player_start(map, player, x, y);
				if (player_found == SUCCESS)
					return (result_error("more then one player found"));
				player_found = SUCCESS;
			}
			x++;
		}
		y++;
	}
	if (player_found == ERROR)
		return (result_error("no player start found"));
	return (player_found);
}
