/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_alive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:43:43 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 12:44:08 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_player_alive(t_game *game)
{
	int	fd;

	sem_wait(game->filelock.sem);
	fd = open(F_PLAYER_STATE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "alive\n", 6);
	sem_post(game->filelock.sem);
}
