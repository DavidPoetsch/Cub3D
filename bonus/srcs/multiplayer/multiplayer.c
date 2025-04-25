/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:54:42 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/23 10:07:19 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	send_rcv(t_game *game)
{
	sem_wait(game->filelock.sem);
	receive_msg(game);
	receive_pos(game);
	send_msgs(&game->snd_rcv);
	send_pos(game);
	sem_post(game->filelock.sem);
}

void	multiplayer(t_game *game)
{
	send_rcv(game);
	handle_game_state(game);
}
