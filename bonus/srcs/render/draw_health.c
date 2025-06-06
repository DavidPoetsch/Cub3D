/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_health.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:45:02 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 12:31:40 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_health(t_game *game)
{
	int		i;
	t_pixel	pxl;

	pxl.color = HEALTH_COLOR_2;
	pxl.x = WIDTH / 2 - 50;
	pxl.y = 20;
	i = 0;
	while (i < HEALTH_MAX)
	{
		if (i >= game->player.health)
			pxl.color = HEALTH_COLOR_1;
		draw_area(&game->mlx.img, pxl, 10);
		pxl.x += 10;
		i += 10;
	}
}
