/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:12:55 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 15:56:53 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player(t_player *player)
{
	player->alive = true;
	player->health = 100;
	player->ammo = 10;
	ft_printf("START X: %d Y: %d\n", player->start_x, player->start_y);
	player->pos = vec_set(player->start_x + 0.5, player->start_y + 0.5);
	player->rotator = vec_set(-1.0, 0.0);
	player->plane = vec_set(0.0, -0.66);
	if (player->dir == 'N')
		rotate_player(player, 90);
	if (player->dir == 'E')
		rotate_player(player, 0);
	if (player->dir == 'S')
		rotate_player(player, 270);
	if (player->dir == 'W')
		rotate_player(player, 180);
}
