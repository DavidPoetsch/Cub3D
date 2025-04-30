/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:48 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/30 10:28:01 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_buf(t_img *img)
{
	if (!img)
		return (result_prog_err(__func__, __FILE__));
	img->buf = (int *)mlx_get_data_addr(img->ptr, &img->pixel_bits,
			&img->line_pixels, &img->endian);
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
	int	res;

	res = SUCCESS;
	if (!img)
		return (result_prog_err(__func__, __FILE__));
	if (!path)
		return (result_error("texture path invalid"));
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->ptr)
	{
		ft_eprintf("Error: failed to open texture for %s\n", path);
		return (ERROR);
	}
	res = init_buf(img);
	return (res);
}
