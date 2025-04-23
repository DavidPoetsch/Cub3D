/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:19:52 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 16:34:23 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_player *player, float angle)
{
	if (player->alive)
	{
		player->rotator = vec_rot_z(player->rotator, angle);
		player->plane = vec_rot_z(player->plane, angle);
	}
}
