/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/23 09:25:28 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	import_textures(void *mlx, t_map *map, t_game *game)
{
	int	res;

	(void)map;
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

static int	import_sprite_textures(void *mlx, t_map *map)
{
	int	res;

	res = open_img(mlx, &map->sprite[0].texs[0],
			"./test/anims/torch/torch00.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &map->sprite[0].texs[1],
				"./test/anims/torch/torch01.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &map->sprite[0].texs[2],
				"./test/anims/torch/torch02.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &map->sprite[0].texs[3],
				"./test/anims/torch/torch01.xpm");
	return (res);
}

int	setup_sprites(t_game *game)
{
	game->map.sprite = ft_calloc(game->map.sprite_count, sizeof(t_sprite));
	if (!game->map.sprite)
		return (result_failed("ft_calloc", __func__, __FILE__));
	game->enemy.sprite.tex = ft_calloc(1, sizeof(t_img));
	if (!game->enemy.sprite.tex)
		return (result_failed("ft_calloc", __func__, __FILE__));
	game->enemy.sprite.pos.x = 2.0;
	game->enemy.sprite.pos.y = 20.5;
	game->enemy.sprite.hidden = false;
	game->enemy.sprite.type = OBJECT;
	game->enemy.sprite.size_adjust = 1;
	game->enemy.sprite.update_t = 0;
	game->enemy.sprite.move = 100;
	game->enemy.sprite.t_id = 0;
	game->enemy.health = 100;
	game->enemy.alive = true;
	open_img(game->mlx.ptr, game->enemy.sprite.tex,
		"./test/textures/soldier.xpm");
	//--------------------------------------------------------------------------------
	game->map.sprite[0].tex_count = 4;
	game->map.sprite[0].texs = ft_calloc(game->map.sprite[0].tex_count,
			sizeof(t_sprite));
	if (!game->map.sprite[0].texs)
		return (result_failed("ft_calloc", __func__, __FILE__));
	game->map.sprite[0].pos.x = 1.05;
	game->map.sprite[0].pos.y = 20.5;
	game->map.sprite[0].hidden = false;
	game->map.sprite[0].type = OBJECT;
	game->map.sprite[0].size_adjust = 2;
	game->map.sprite[0].update_t = 500;
	game->map.sprite[0].move = -100;
	game->map.sprite[0].t_id = 0;
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
	game->mlx.center.x = WIDTH / 2;
	game->mlx.center.y = HEIGHT / 2;
	init_player(&game->player);
	game->delta_sec = get_delta_seconds();
	game->map.sprite_count = 1;
	res = import_textures(game->mlx.ptr, &game->map, game);
	if (res == SUCCESS)
		res = setup_sprites(game);
	if (res == SUCCESS)
		res = init_multiplayer(game);
	return (res);
}
