/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:38 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/23 12:41:25 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	collect_ammo(t_game *game, t_sprite *sprite)
{
	if (!sprite->hidden)
	{
		game->player.ammo = AMMO_MAX;
		sprite->hide_time = AMMO_HIDE_TIME;
		sprite->hidden = true;
	}
}

void	check_ammo_visibility(t_game *game, t_sprite *sprite)
{
	if (sprite->hidden)
	{
		sprite->hide_time -= game->delta_sec;
		if (sprite->hide_time <= 0)
		{
			sprite->hide_time = 0;
			sprite->hidden = false;
		}
	}
}
