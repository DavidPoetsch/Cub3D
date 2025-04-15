/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:48 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 10:58:39 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_buf(t_img *img)
{
	if (!img)
		return (result_prog_err(__func__, __FILE__));
	img->buf = (int *)mlx_get_data_addr(
		img->ptr,
		&img->pixel_bits,
		&img->line_pixels,
		&img->endian);
	img->line_pixels /= 4;
	if (!img->buf)
		return (result_failed("mlx_get_data_addr", __func__, __FILE__));
	return (SUCCESS);
}

/**
 * @brief ### Open image
 *
 * @param mlx mlx pointer
 * @param img image struct
 * @param path path to texture
 * @return int SUCCESS or ERROR
 */
int	open_img(void *mlx, t_img *img, char *path)
{
	int res;

	res = SUCCESS;
	if (!img)
		return (result_prog_err(__func__, __FILE__));
	if (!path)
		return (result_error("texture path not found"));
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->ptr)
		return (result_failed("mlx_xpm_file_to_image", __func__, __FILE__));
	res = init_buf(img);
	return (res);
}
