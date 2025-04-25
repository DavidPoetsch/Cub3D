/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:38 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 16:22:46 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	collect_ammo(t_game *game, t_sprite *sprite)
{
	if (!sprite->hidden)
	{
		if (game->player.ammo == AMMO_MAX)
			game->player.reloads = 1;
		else
			game->player.ammo = AMMO_MAX;
		sprite->hide_time = AMMO_HIDE_TIME;
		sprite->hidden = true;
		send_hide_collectable(game, sprite->pos.x, sprite->pos.y);
	}
}
