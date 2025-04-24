/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_pack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:38 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 09:17:56 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	collect_health(t_game *game, t_sprite *sprite)
{
	if (!sprite->hidden)
	{
		sprite->hide_time = AMMO_HIDE_TIME;
		sprite->hidden = true;
		enqueue_msg(&game->snd_rcv, "health\n");
	}
}
