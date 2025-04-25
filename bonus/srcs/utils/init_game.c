/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 12:32:46 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	init_player(&game->player);
	game->delta_sec = get_delta_seconds();
	res = init_distbuff(game);
	if (res == SUCCESS)
		res = init_multiplayer(game);
	return (res);
}
