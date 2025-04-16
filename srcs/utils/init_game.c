/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/16 16:39:51 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player(t_player *player)
{
	printf("START X: %d Y: %d\n", player->x, player->y);
	player->pos = vec_set(player->x, player->y);
	player->rotator = vec_set(-1.0, 0.0);
	player->plane = vec_set(0.0, 0.66);
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

static int import_sprite_textures(void *mlx, t_map *map)
{
	int	res;

	res = open_img(mlx, &map->sprite[0].tex, "./test/textures/can.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &map->sprite[1].tex, "./test/textures/door.xpm");
	return (res);
}

int setup_sprites(t_game *game)
{
	game->map.sprite = ft_calloc(game->map.sprite_count, sizeof(t_sprite));
	if (!game->map.sprite)
		return (result_failed("ft_calloc", __func__, __FILE__));
	game->map.sprite[0].pos.x = 5.5;
	game->map.sprite[0].pos.y = 20.5;
	game->map.sprite[0].hidden = false;
	game->map.sprite[0].type = COLLECT;
	game->map.sprite[0].size_adjust = 3;
	game->map.sprite[0].offset = -500;
	game->map.sprite[1].pos.x = 3.0;
	game->map.sprite[1].pos.y = 20.2;
	game->map.sprite[1].hidden = false;
	game->map.sprite[1].type = OBJECT;
	game->map.sprite[1].size_adjust = 1;
	game->dist_buff = ft_calloc(WIDTH, sizeof(double));
	if (!game->dist_buff)
		return (result_failed("ft_calloc", __func__, __FILE__));
	return (import_sprite_textures(game->mlx.ptr, &game->map));
}

int	init_game(t_game *game)
{
	int	res;

	if (!game)
		return (result_prog_err(__func__, __FILE__));
	init_player(&game->player);
	ft_bzero(&game->keys, sizeof(t_keys));
	game->render.delta_seconds = get_delta_seconds();
	game->map.sprite_count = 2;
	res = import_textures(game->mlx.ptr, &game->map);
	if (res == SUCCESS)
		res = setup_sprites(game);
	return (res);
}
