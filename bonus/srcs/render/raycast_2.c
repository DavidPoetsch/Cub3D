/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:13 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 15:37:36 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_raycast(t_player *player, t_raycast *rc)
{
	rc->x = 0;
	rc->pos.x = player->pos.x;
	rc->pos.y = player->pos.y;
	rc->dir.x = player->rotator.x;
	rc->dir.y = player->rotator.y;
	rc->plane.x = player->plane.x;
	rc->plane.y = player->plane.y;
}
