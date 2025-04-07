/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:09 by dpotsch           #+#    #+#             */
/*   Updated: 2025/02/24 11:59:05 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_all_buffers(t_list_manager *lm)
{
	t_file_handler	*curr_fh;
	t_file_handler	*next_fh;

	curr_fh = lm->first;
	while (curr_fh)
	{
		next_fh = curr_fh->next;
		free(curr_fh->buff);
		curr_fh->buff = NULL;
		free(curr_fh);
		curr_fh = next_fh;
	}
	lm->first = NULL;
	lm->last = NULL;
}

static void	free_fd_buffer(t_list_manager *lm, int fd)
{
	t_file_handler	*curr_fh;
	t_file_handler	*prev_fh;

	curr_fh = lm->first;
	prev_fh = NULL;
	while (curr_fh)
	{
		if (curr_fh->fd == fd)
		{
			if (prev_fh)
				prev_fh->next = curr_fh->next;
			else
				lm->first = curr_fh->next;
			free(curr_fh->buff);
			curr_fh->buff = NULL;
			free(curr_fh);
			return ;
		}
		prev_fh = curr_fh;
		curr_fh = curr_fh->next;
	}
}

void	gnl_free_buffers(t_list_manager *lm, int fd, int gnl_cmd)
{
	if (gnl_cmd == GNL_FREE)
		free_fd_buffer(lm, fd);
	if (gnl_cmd == GNL_FREE_ALL)
		free_all_buffers(lm);
}
