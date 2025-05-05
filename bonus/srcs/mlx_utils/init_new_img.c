/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:12:38 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 10:57:49 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_img(void *mlx, t_img *img, int width, int height)
{
	if (!img || !mlx)
		return (result_prog_err(__func__, __FILE__));
	img->width = width;
	img->height = height;
	img->ptr = mlx_new_image(mlx, width, height);
	if (!img->ptr)
		return (result_failed("mlx_new_image", __func__, __FILE__));
	return (SUCCESS);
}

int	init_buf(t_img *img)
{
	if (!img || !img->ptr)
		return (result_prog_err(__func__, __FILE__));
	img->buf = (int *)mlx_get_data_addr(img->ptr, &img->pixel_bits,
			&img->line_pixels, &img->endian);
	img->line_pixels /= 4;
	if (!img->buf)
		return (result_error("failed to initialize mlx image buffer"));
	return (SUCCESS);
}

int	init_new_img(void *mlx, t_img *img, int width, int height)
{
	int	res;

	res = init_img(mlx, img, width, height);
	if (res == SUCCESS)
		res = init_buf(img);
	return (res);
}
