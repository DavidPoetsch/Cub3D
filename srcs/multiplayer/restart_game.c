/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:19:15 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 16:25:53 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	restart_game(t_game *game)
{
	size_t ms;

	if (game->player.alive)
		return;
	if (game->state == GAME_RUNING)
	{
		game->restart_time = get_time_ms() + RESTART_TIME * 1000;
		game->state = GAME_RESTART;
		ft_printf("wait for restart\n");
		return ;
	}
	ms = get_time_ms();
	if (ms > game->restart_time)
	{
		ft_printf("game restarted\n");
		game->state = GAME_RUNING;
		game->player.alive = true;
		game->player.pos.x = game->player.start_x;
		game->player.pos.y = game->player.start_y;
		game->enemy.alive = true;
		game->enemy.health = 100;
		put_msg_in_send_list(&game->snd_rcv, "restart\n");
		return;
	}
}
