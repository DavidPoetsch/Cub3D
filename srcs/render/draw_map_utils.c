/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:56:57 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 09:22:10 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_minimap_ray(t_game *game, t_pixel pxl_center)
{
	double	ray_len;
	double	max_len;

	pxl_center.color = MAP_DOOR_COLOR;
	ray_len = game->minimap.mini_map_ray_len * game->minimap.tilesize;
	max_len = MAP_SIZE / 2 * game->minimap.tilesize - 2;
	if (ray_len > max_len)
		ray_len = max_len;
	draw_line(&game->minimap.img, pxl_center, game->player.rotator, ray_len);
}
