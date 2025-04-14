/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/09 14:21:33 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_player(t_game *game)
{
	game->player.cam.pos = vec_set(4.0, 2.0, 0.0);
}

int	init_game(t_game *game)
{
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	init_player(game);
	game->render.delta_seconds = get_delta_seconds();

	game->player.cam.rotator.x = -1.0;
	game->player.cam.rotator.y = 0.0;
	game->render.plane.x = 0.0;
	game->render.plane.y = 0.66;
	return (SUCCESS);
}
