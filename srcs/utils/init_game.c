/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:23:59 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	import_textures(void *mlx, t_game *game)
{
	int	res;

	res = open_img(mlx, &game->img_victory, "./test/textures/victory.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &game->img_defeat, "./test/textures/defeat.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &game->img_pistol, "./test/textures/pistol.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &game->img_pistol_shot,
				"./test/textures/pistol_shot.xpm");
	return (res);
}

int	init_distbuff(t_game *game)
{
	game->dist_buff = ft_calloc(WIDTH, sizeof(double));
	if (!game->dist_buff)
		return (result_failed("ft_calloc", __func__, __FILE__));
	return (SUCCESS);
}

int	init_game(t_game *game)
{
	int	res;

	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.center.x = WIDTH / 2;
	game->mlx.center.y = HEIGHT / 2;
	init_player(&game->player);
	game->delta_sec = get_delta_seconds();
	res = import_textures(game->mlx.ptr, game);
	if (res == SUCCESS)
		res = init_distbuff(game);
	if (res == SUCCESS)
		res = init_multiplayer(game);
	return (res);
}
