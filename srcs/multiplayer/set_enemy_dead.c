/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_dead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:23:43 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 14:25:45 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_enemy_dead(t_game *game)
{
	game->enemy.alive = false;
	game->enemy.health = 0;
	enqueue_msg(&game->snd_rcv, "dead\n");
	game->restart_time = get_time_ms() + RESTART_TIME * 1000;
	game->state = GAME_RESTART;
	game->map.arr[game->enemy.grid.y][game->enemy.grid.x] = '0';
}
