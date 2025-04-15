/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/15 15:52:39 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player(t_player *player)
{
	printf("START X: %d Y: %d\n", player->x, player->y);
	player->pos = vec_set(player->x, player->y, 0.0);
	player->rotator = vec_set(-1.0, 0.0, 0.0);
	player->plane = vec_set(0.0, 0.66, 0.0);
	if (player->dir == 'N')
		rotate_player(player, 90);
	if (player->dir == 'E')
		rotate_player(player, 0);
	if (player->dir == 'S')
		rotate_player(player, 270);
	if (player->dir == 'W')
		rotate_player(player, 180);
}

static int	import_textures(void *mlx, t_map *map)
{
	int	res;

	res = open_img(mlx, &map->NO_tex, map->NO_tex_path);
	if (res == SUCCESS)
		res = open_img(mlx, &map->EA_tex, map->EA_tex_path);
	if (res == SUCCESS)
		res = open_img(mlx, &map->SO_tex, map->SO_tex_path);
	if (res == SUCCESS)
		res = open_img(mlx, &map->WE_tex, map->WE_tex_path);
	if (res == SUCCESS) //BONUS
		res = open_img(mlx, &map->D_tex, "./test/textures/door.xpm");
	return (res);
}

int	init_game(t_game *game)
{
	int	res;

	if (!game)
		return (result_prog_err(__func__, __FILE__));
	init_player(&game->player);
	ft_bzero(&game->keys, sizeof(t_keys));
	game->render.delta_seconds = get_delta_seconds();
	res = import_textures(game->mlx.ptr, &game->map);
	return (res);
}
