/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:19:15 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/22 15:56:42 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_game_restart(t_game *game)
{
	if (!game->player.alive && game->state == GAME_RUNING)
	{
		game->restart_time = get_time_ms() + RESTART_TIME * 1000;
		game->state = GAME_RESTART;
		ft_printf("wait for restart\n");
	}
}

static void	wait_until_restart(t_game *game)
{
	size_t	ms;

	ms = get_time_ms();
	if (ms > game->restart_time)
	{
		ft_printf("game restarted\n");
		game->state = GAME_RUNING;
		init_player(&game->player);
		game->enemy.alive = true;
		game->enemy.health = 100;
		enqueue_msg(&game->snd_rcv, "restart\n");
		return ;
	}
}

void	handle_game_state(t_game *game)
{
	if (!game->player.alive && game->state == GAME_RUNING)
		set_game_restart(game);
	if (game->state == GAME_RESTART)
		wait_until_restart(game);
}
