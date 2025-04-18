/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:54:42 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 09:03:35 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_semaphore(t_sem *sem, int value)
{
	if (!sem || !sem->name)
		return (ERROR);
	sem->state = SEM_STATE_FAILED;
	sem->sem = sem_open(sem->name, O_CREAT | O_EXCL, 0644, value);
	if (sem->sem == SEM_FAILED)
	{
		sem_unlink(sem->name);
		sem->sem = sem_open(sem->name, O_CREAT | O_EXCL, 0644, value);
		if (sem->sem == SEM_FAILED)
			return (result_failed("sem_open", __func__, __FILE__));
	}
	sem->state = SEM_STATE_OPEN;
	return (SUCCESS);
}

void	multiplayer(t_game *game)
{
	static int init = 0;

	if (!init)
	{
		ft_bzero(&game->filelock, sizeof(t_sem));
		game->filelock.name = SEM_FILE_LOCK;
		init_semaphore(&game->filelock, 1);
	}
	sem_wait(game->filelock.sem);
	update_player_pos(game);
	read_enemy_pos(game);
	check_player_state(game);
	sem_post(game->filelock.sem);
}
