/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_pack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:38 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/05 10:36:37 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	collect_health(t_game *game, t_sprite *sprite)
{
	if (!sprite->hidden)
	{
		sprite->hide_time = HEALTH_HIDE_TIME;
		sprite->hidden = true;
		send_hide_collectable(game, sprite->pos.x, sprite->pos.y);
		if (game->player.health > 0)
			game->player.health += HEALTH_PACK;
		if (game->player.health > HEALTH_MAX)
			game->player.health = HEALTH_MAX;
	}
}
