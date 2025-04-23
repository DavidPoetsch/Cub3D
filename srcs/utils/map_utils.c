/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:57:10 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/23 11:35:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

inline __attribute__((always_inline))
bool	is_collision(char **map, int x, int y)
{
	return (map[y][x] == WALL || map[y][x] == DOOR);
}

inline __attribute__((always_inline))
bool	is_door(char **map, int x, int y)
{
	return (map[y][x] == DOOR);
}

inline __attribute__((always_inline))
bool	is_enemy(char **map, int x, int y)
{
	return (map[y][x] == ENEMY);
}

inline __attribute__((always_inline))
bool	is_player(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

inline __attribute__((always_inline))
bool	is_valid_map_char(char c)
{
	if (!is_player(c))
		return (false);
	if (c != WALL && c != OPEN)
		return (false);
	if (c != DOOR)
		return (false);
	return (true);
}
