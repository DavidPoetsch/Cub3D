/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:54:21 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 11:37:46 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	send_msg(char *msg, bool send_now)
{
	int	fd;

	if (!msg)
		return (ERROR);
	if (!send_now && !file_is_empty(F_SND_MSG))
		return (ERROR);
	fd = open(F_SND_MSG, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ERROR);
	write(fd, msg, ft_strlen(msg));
	return (SUCCESS);
}

void	send_msgs(t_snd_rcv *sr)
{
	int	i;

	if (!sr || sr->i_buf < 0)
		return ;
	if (send_msg(sr->msg_lst[0], false) == ERROR)
		return ;
	ft_putstr_fd("[SENT]: ", STDOUT_FILENO);
	ft_putstr_fd(sr->msg_lst[0], STDOUT_FILENO);
	i = 1;
	while (i <= sr->i_buf)
	{
		ft_strlcpy(sr->msg_lst[i - 1], sr->msg_lst[i], MSG_SIZE);
		i++;
	}
	sr->i_buf--;
}
