/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:52:45 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/08 09:11:03 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int init_mlx(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return (result_error("failed to initialize mlx"));
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	if (!game->mlx.win)
		return (result_error("failed to create new window"));
	return (SUCCESS);
}
