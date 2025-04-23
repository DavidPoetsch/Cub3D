/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 12:13:17 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player(t_player *player)
{
	player->alive = true;
	printf("START X: %d Y: %d\n", player->start_x, player->start_y);
	player->pos = vec_set(player->start_x + 0.5, player->start_y + 0.5);
	player->rotator = vec_set(-1.0, 0.0);
	player->plane = vec_set(0.0, -0.66);
	if (player->dir == 'N')
		rotate_player(player, 90);
	if (player->dir == 'E')
		rotate_player(player, 0);
	if (player->dir == 'S')
		rotate_player(player, 270);
	if (player->dir == 'W')
		rotate_player(player, 180);
}

static int	import_textures(void *mlx, t_game *game)
{
	int	res;

	res = open_img(mlx, &game->img_victory, "./test/textures/victory.xpm");
	if (res == SUCCESS)
		res = open_img(mlx, &game->img_defeat, "./test/textures/defeat.xpm");
	return (res);
}

int init_distbuff(t_game *game)
{
	printf("WIDTH: %d\n", WIDTH);
	game->dist_buff = ft_calloc(WIDTH, sizeof(double));
	if (!game->dist_buff)
		return (result_failed("ft_calloc", __func__, __FILE__));
	return (SUCCESS);
}

int	init_game(t_game *game)
{
	int	res;

	res = SUCCESS;
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	game->mlx.center.x = WIDTH / 2;
	game->mlx.center.y = HEIGHT / 2;
	init_player(&game->player);
	ft_bzero(&game->keys, sizeof(t_keys));
	game->delta_sec = get_delta_seconds();
	game->snd_rcv.i_buf = -1;
	res = import_textures(game->mlx.ptr, game);
	if (res == SUCCESS)
		res = init_distbuff(game);
	if (res == SUCCESS)
		res = init_semaphore(&game->filelock, SEM_FILE_LOCK, 1);
	if (res == SUCCESS)
		set_player_alive(game);
	return (res);
}
