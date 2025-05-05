/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:57:10 by lstefane          #+#    #+#             */
/*   Updated: 2025/05/05 14:17:54 by lstefane         ###   ########.fr       */
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
	if (is_player(c))
		return (true);
	if (c == WALL || c == OPEN || c == DOOR)
		return (true);
	if (is_sprite(c))
		return (true);
	return (false);
}
