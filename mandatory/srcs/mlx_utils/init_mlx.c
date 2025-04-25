/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:52:45 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 16:02:38 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx_ptr(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (result_error("failed to initialize mlx"));
	return (SUCCESS);
}

int	init_mlx_win(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	if (!game->mlx.win)
		return (result_error("failed to create new window"));
	return (SUCCESS);
}

int	init_mlx_stuff(t_game *game)
{
	int	res;

	res = init_mlx_ptr(game);
	if (res == SUCCESS)
		res = init_new_img(game->mlx.ptr, &game->mlx.img, WIDTH, HEIGHT);
	return (res);
}
