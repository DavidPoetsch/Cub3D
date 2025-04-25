/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:57:10 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 16:14:45 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

inline __attribute__((always_inline))
bool	is_collision(char **map, int x, int y)
{
	return (map[y][x] == WALL);
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
	if (c == WALL || c == OPEN)
		return (true);
	return (false);
}
