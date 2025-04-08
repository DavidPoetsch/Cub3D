/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:21:34 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/07 17:45:09 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_player(char c)
{
	return(c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool	check_player_start(t_map map)
{
	int	i;
	int	j;
	bool player_found;

	j = 0;
	player_found = false;
	while(map.map[j][i])
	{
		i = 0;
		while(map.map[j][i])
		{
			if (is_player(map.map[j][i]))
			{
				map.player_x = i;
				map.player_y = j;
				if (player_found)
					return (false);
				player_found = true;
			}
			i++;
		}
		j++;
	}
	return (true);
}

bool check_map(char **map, int i, int j)
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
}

bool is_map_valid(t_map map)
{
	int res;

	res = check_player_start(map);
	if (res)
		check_map(map.map, map.player_y, map.player_x);
	return (res);
}