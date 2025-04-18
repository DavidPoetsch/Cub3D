/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_map_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:47:04 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 16:31:47 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_nbr_buf(int n, char buf[MSG_SIZE], int *i)
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
 * @brief ### Send map update
 *
 * `map[y,x]=D`
 */
void	send_map_update(t_game *game, int x, int y, char map_char)
{
	int		i;
	char	buf[MSG_SIZE];

	i = 0;
	ft_bzero(buf, MSG_SIZE);
	ft_strlcat(buf, "map[", MSG_SIZE);
	i = ft_strlen(buf);
	put_nbr_buf(y, buf, &i);
	if (i < MSG_SIZE)
		buf[i++] = ',';
	put_nbr_buf(x, buf, &i);
	if (i < MSG_SIZE)
		buf[i++] = ']';
	if (i < MSG_SIZE)
		buf[i++] = '=';
	if (i < MSG_SIZE)
		buf[i++] = map_char;
	if (i < MSG_SIZE)
		buf[i++] = '\n';
	buf[i] = '\0';
	sem_wait(game->filelock.sem);
	put_msg_in_send_list(&game->snd_rcv, buf);
	sem_post(game->filelock.sem);
	ft_printf("map update: %s", buf);
}
