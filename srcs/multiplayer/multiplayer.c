/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:54:42 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/18 17:04:30 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_msg_in_send_list(t_snd_rcv *sr, char *msg)
{
	if (!sr || sr->i_buf + 1 >= MSG_LST_SIZE)
		return ;
	ft_printf("enqueue msg: %s", msg);
	sr->i_buf++;
	ft_bzero(&sr->msg_lst[sr->i_buf], sizeof(MSG_SIZE));
	ft_strlcpy(sr->msg_lst[sr->i_buf], msg, MSG_SIZE);
}

void	send_msgs(t_snd_rcv *sr)
{
	int	i;

	if (!sr || sr->i_buf < 0)
		return ;
	if (send_state(sr->msg_lst[0], false) == ERROR)
		return ;
	ft_printf("Sending: %s", sr->msg_lst[0]);
	i = 1;
	while (i <= sr->i_buf)
	{
		ft_strlcpy(sr->msg_lst[i - 1], sr->msg_lst[i], MSG_SIZE);
		i++;
	}
	sr->i_buf--;
}

void	multiplayer(t_game *game)
{
	sem_wait(game->filelock.sem);
	update_player_pos(game);
	read_enemy_pos(game);
	check_player_state(game);
	restart_game(game);
	send_msgs(&game->snd_rcv);
	sem_post(game->filelock.sem);
}
