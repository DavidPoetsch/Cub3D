/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:53 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 11:37:39 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void clear_image(t_img *img, int color)
{
	t_pixel pxl;

	if (!img)
		return ;
	pxl.color = color;
	pxl.y = 0;
	while (pxl.y < img->height)
	{
		pxl.x = 0;
		while (pxl.x < img->width)
		{
			put_pixel(img, pxl);
			pxl.x++;
		}
		pxl.y++;
	}
}

void draw_background(t_img *img, t_map *map)
{
	t_pixel pxl;

	if (!img)
		return ;
	pxl.y = 0;
	while (pxl.y < img->height)
	{
		pxl.x = 0;
		while (pxl.x < img->width)
		{
			pxl.color = map->ceiling->col;
			if (pxl.y >= HEIGHT / 2)
				pxl.color = map->floor->col;
			put_pixel(img, pxl);
			pxl.x++;
		}
		pxl.y++;
	}
}