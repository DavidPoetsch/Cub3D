/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:23:21 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/24 10:55:43 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_sprite(char tile)
{
	if (tile == TORCH)
		return (true);
	if (tile == AMMO)
		return (true);
	if (tile == ENEMY)
		return (true);
	if (tile == HEALTH)
		return (true);
	return (false);
}

int	is_map_element(char c)
{
	if (c == WALL)
		return (true);
	if (c == OPEN)
		return (true);
	if (c == DOOR)
		return (true);
	if (c == ENEMY)
		return (true);
	if (c == TORCH)
		return (true);
	if (c == AMMO)
		return (true);
	if (c == HEALTH)
		return (true);
	return (false);
}
