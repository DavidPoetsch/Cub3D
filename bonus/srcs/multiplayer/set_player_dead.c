/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:23:43 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 11:28:34 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_player_dead(t_game *game)
{
	enqueue_msg(&game->snd_rcv, "dead\n");
	game->player.health = 0;
	game->restart_time = get_time_ms() + RESTART_TIME * 1000;
	game->state = GAME_RESTART;
}
