/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:14:27 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/25 14:31:43 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_game(t_game *game)
{
	int	res;

	res = SUCCESS;
	if (!game)
		return (result_prog_err(__func__, __FILE__));
	init_player(&game->player);
	game->delta_sec = get_delta_seconds();
	return (res);
}
