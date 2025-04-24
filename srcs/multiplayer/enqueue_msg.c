/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:40:33 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 12:43:29 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	enqueue_msg(t_snd_rcv *sr, char *msg)
{
	if (!sr || sr->i_buf + 1 >= MSG_LST_SIZE)
		return ;
	sr->i_buf++;
	ft_bzero(&sr->msg_lst[sr->i_buf], sizeof(MSG_SIZE));
	ft_strlcpy(sr->msg_lst[sr->i_buf], msg, MSG_SIZE);
}
