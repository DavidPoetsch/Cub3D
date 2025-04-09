/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:53 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 13:38:55 by dpotsch          ###   ########.fr       */
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
