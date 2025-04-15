/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:57:10 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/15 15:09:12 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_collision(char **map, int x, int y)
{
	return (map[y][x] == WALL);
}

bool	is_inbounds(char **map, int x, int y)
{
	return (map[y][x] == WALL || map[y][x] == OPEN);
}

bool	is_door(char **map, int x, int y)
{
	return (map[y][x] == DOOR);
}

bool	is_player(char c)
{
	return(c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool is_valid_map_char(char c)
{
	if (!is_player(c))
		return (false);
	if (c != WALL && c != OPEN)
		return (false);
	if (c != DOOR) //BONUS
		return (false);
	return (true);
}
