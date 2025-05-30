/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:25:46 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:05:07 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_sprite_visibility(t_game *game, t_sprite *sprite)
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

void	check_collectables(t_game *game, t_sprite *sprite)
{
	if (sprite->dist <= 1 && sprite->is_collectable)
	{
		if (sprite->type == AMMO)
			collect_ammo(game, sprite);
		else if (sprite->type == HEALTH)
			collect_health(game, sprite);
	}
	if (sprite->type == AMMO || sprite->type == HEALTH)
		check_sprite_visibility(game, sprite);
}
