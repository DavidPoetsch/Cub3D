/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_multiplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:49 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 11:42:17 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_send_msg_file(void)
{
	int	fd;

	fd = open(F_SND_MSG, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (result_error("failed to open send_msg.txt"));
	write(fd, "alive\n", 6);
	return (SUCCESS);
}

static int	init_files(t_game *game)
{
	int res;

	sem_wait(game->filelock.sem);
	res = init_send_msg_file();
	if (res == SUCCESS)
		res = clear_file(F_SND_POS);
	if (res == SUCCESS)
		res = clear_file(F_RCV_POS);
	if (res == SUCCESS)
		res = clear_file(F_RCV_MSG);
	sem_post(game->filelock.sem);
	return (res);
}

int	init_multiplayer(t_game *game)
{
	int	res;

	game->snd_rcv.i_buf = -1;
	res = init_semaphore(&game->filelock, SEM_FILE_LOCK, 1);
	if (res == SUCCESS)
		res = init_files(game);
	return (res);
}
