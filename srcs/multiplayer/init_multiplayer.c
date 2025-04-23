/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_multiplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:49 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/23 09:24:31 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_send_msg_file(void)
{
	int	fd;

	fd = open(F_SND_MSG, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "alive\n", 6);
}

static void	init_files(t_game *game)
{
	sem_wait(game->filelock.sem);
	init_send_msg_file();
	clear_file(F_SND_POS);
	clear_file(F_RCV_POS);
	clear_file(F_RCV_MSG);
	sem_post(game->filelock.sem);
}

int	init_multiplayer(t_game *game)
{
	int	res;

	game->snd_rcv.i_buf = -1;
	res = init_semaphore(&game->filelock, SEM_FILE_LOCK, 1);
	if (res == SUCCESS)
		init_files(game);
	return (res);
}
