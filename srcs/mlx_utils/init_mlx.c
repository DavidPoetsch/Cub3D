/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:52:45 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/11 12:13:34 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_mlx_ptr(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (result_error("failed to initialize mlx"));
	return (SUCCESS);
}

int	init_win(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	if (!game->mlx.win)
		return (result_error("failed to create new window"));
	return (SUCCESS);
}

int	init_img(t_game *game)
{
	if (!game || !game->mlx.ptr)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.img.width = WIDTH;
	game->mlx.img.height = HEIGHT;
	game->mlx.img.ptr = mlx_new_image(game->mlx.ptr, WIDTH, HEIGHT);
	if (!game->mlx.img.ptr)
		return (result_error("failed to initialize mlx image"));
	return (SUCCESS);
}

int	init_buf(t_game *game)
{
	t_img *img;

	if (!game || !game->mlx.img.ptr)
		return (result_prog_err(__func__, __FILE__));

	img = &game->mlx.img;
	img->buf = (int *)mlx_get_data_addr(
		img->ptr,
		&img->pixel_bits,
		&img->line_pixels,
		&img->endian);
	img->line_pixels /= 4;
	if (!img->buf)
		return (result_error("failed to initialize mlx image buffer"));
	return (SUCCESS);
}

int	init_mlx_stuff(t_game *game)
{
	int	res;

	res = init_mlx_ptr(game);
	if (res == SUCCESS)
		res = init_win(game);
	if (res == SUCCESS)
		res = init_img(game);
	if (res == SUCCESS)
		res = init_buf(game);
	if (res == SUCCESS)
		mlx_mouse_hide(game->mlx.ptr, game->mlx.win);
	return (res);
}
