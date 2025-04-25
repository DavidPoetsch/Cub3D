/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:58:10 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 12:39:39 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_wall(char **map, int x, int y)
{
	return (map[y][x] == WALL);
}

bool	is_floor(char **map, int x, int y)
{
	return (map[y][x] == OPEN);
}
