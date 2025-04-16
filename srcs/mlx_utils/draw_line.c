/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:49:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 15:02:02 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_game *game, t_pixel start, t_vec dir, double length)
{
	int		i;
	double	mag;
	t_pixel	pxl;
	t_vec	unit;
	t_vec	pos;

	mag = sqrtf(dir.x * dir.x + dir.y * dir.y);
	if (mag == 0)
		return ;
	unit.x = dir.x / mag;
	unit.y = dir.y / mag;
	pos.x = start.x;
	pos.y = start.y;
	i = 0;
	pxl.color = MAP_DOOR_COLOR;
	while (i <= (int)length)
	{
		pxl.x = (int)(pos.x + 0.5f);
		pxl.y = (int)(pos.y + 0.5f);
		put_pixel(&game->mlx.img, pxl);
		pos.x += unit.x;
		pos.y += unit.y;
		i++;
	}
}
