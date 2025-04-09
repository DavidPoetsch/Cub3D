/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:57:35 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 12:58:32 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* bool check_map(char **map, int i, int j)
{
	bool valid;

	valid = true;
	if (!map[i][j])
		return (false);
	else if (map[i][j] == WALL)
		return (true);
	else if (is_player(map[i][j]) || map[i][j] == '0')
	{
		check_map(map, i - 1, j);
		check_map(map, i, j - 1);
		check_map(map, i - 1, j - 1);
		check_map(map, i + 1, j);
		check_map(map, i, j + 1);
		check_map(map, i + 1, j + 1);
		check_map(map, i + 1, j - 1);
		check_map(map, i - 1, j + 1);
	}
} */

/* bool is_map_valid(t_map *map)
{
	int res;

	if (res)
		check_map(map.map, map.player_y, map.player_x);
	return (res);
} */