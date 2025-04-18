/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:52:45 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 16:30:33 by lstefane         ###   ########.fr       */
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

int	init_mlx_stuff(t_game *game)
{
	int	res;

	game->minimap.size = MAP_TILES * MAP_TILE_SIZE + 2 * MAP_PADDING;
	res = init_mlx_ptr(game);
	if (res == SUCCESS)
		res = init_win(game);
	if (res == SUCCESS)
		res = init_new_img(game->mlx.ptr, &game->mlx.img, WIDTH, HEIGHT);
	if (res == SUCCESS)
		res = init_new_img(game->mlx.ptr, &game->minimap.img,
				game->minimap.size, game->minimap.size);
	if (res == SUCCESS)
		mlx_mouse_hide(game->mlx.ptr, game->mlx.win);
	return (res);
}
