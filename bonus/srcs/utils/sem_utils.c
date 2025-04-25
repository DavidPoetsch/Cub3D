/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:28:29 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 12:47:03 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_semaphore(t_sem *sem, char *name, int value)
{
	if (!sem || !name)
		return (ERROR);
	sem->name = name;
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

int	close_semaphore(t_sem *sem, bool unlink)
{
	if (!sem || !sem->name)
		return (ERROR);
	if (sem->state != SEM_STATE_OPEN)
		return (SUCCESS);
	if (sem_close(sem->sem) == FAILED)
		result_error("failed to close semaphore");
	sem->state = SEM_STATE_CLOSED;
	if (unlink && sem_unlink(sem->name) == FAILED)
		result_error("failed to unlink semaphore");
	sem->state = SEM_STATE_UNLINKED;
	return (SUCCESS);
}
