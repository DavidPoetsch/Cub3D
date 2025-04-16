/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:12:50 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 14:14:38 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_area(t_game *game, t_pixel pxl, int size)
{
	int	i;
	int	j;
	int	y_start;

	i = 0;
	y_start = pxl.y;
	while (i < size)
	{
		j = 0;
		pxl.y = y_start;
		while (j < size)
		{
			put_pixel(&game->mlx.img, pxl);
			pxl.y++;
			j++;
		}
		pxl.x++;
		i++;
	}
}
