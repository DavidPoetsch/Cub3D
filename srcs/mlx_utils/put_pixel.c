/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:08:08 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 12:50:40 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_img *img, t_pixel pxl)
{
	int	pixel_position;

	if (!img)
		return ;
	if (pxl.x <= 0 || pxl.y <= 0 || pxl.x >= img->width || pxl.y >= img->height)
		return ;
	pixel_position = (pxl.y * img->line_pixels) + pxl.x;
	img->buf[pixel_position] = pxl.color;
}
