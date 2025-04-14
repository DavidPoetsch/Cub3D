/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/14 14:19:39 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_player(t_player *player)
{
	printf("START X: %d Y: %d\n", player->x, player->y);
	player->pos = vec_set(player->x, player->y, 0.0);
	player->rotator = vec_set(-1.0, 0.0, 0.0);
	player->plane = vec_set(0.0, 0.66, 0.0);
	if (player->dir == 'N')
	{
		rotate_player(player, 90);
	}
	if (player->dir == 'E')
	{
		rotate_player(player, 0);
	}
	if (player->dir == 'S')
	{
		rotate_player(player, 270);
	}
	if (player->dir == 'W')
	{
		rotate_player(player, 180);
	}
}

int	init_game(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	init_player(&game->player);
	game->render.delta_seconds = get_delta_seconds();


	return (SUCCESS);
}
