/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:12:50 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 13:43:18 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_area(t_img *img, t_pixel pxl, int size)
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
			put_pixel(img, pxl);
			pxl.y++;
			j++;
		}
		pxl.x++;
		i++;
	}
}
