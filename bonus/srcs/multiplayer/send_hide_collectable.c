/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_hide_collectable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:47:04 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:03:57 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	put_nbr_buf(int n, char buf[MSG_SIZE], int *i)
{
	if (n >= 10)
		put_nbr_buf(n / 10, buf, i);
	if (*i < MSG_SIZE)
	{
		buf[*i] = (n % 10) + '0';
		(*i)++;
	}
}

/**
 * @brief ### Send hide collectable
 *
 * `hide[y,x]`
 */
void	send_hide_collectable(t_game *game, int x, int y)
{
	int		i;
	char	buf[MSG_SIZE];

	i = 0;
	ft_bzero(buf, MSG_SIZE);
	ft_strlcat(buf, "hide[", MSG_SIZE);
	i = ft_strlen(buf);
	put_nbr_buf(y, buf, &i);
	if (i < MSG_SIZE)
		buf[i++] = ',';
	put_nbr_buf(x, buf, &i);
	if (i < MSG_SIZE)
		buf[i++] = ']';
	if (i < MSG_SIZE)
		buf[i++] = '\n';
	buf[i] = '\0';
	sem_wait(game->filelock.sem);
	enqueue_msg(&game->snd_rcv, buf);
	sem_post(game->filelock.sem);
}
