/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:18:28 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 16:40:32 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_release_event(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == LMB)
		game->mouse.lmb_pressed = 0;
	if (button == MMB)
		game->mouse.mmb_pressed = 0;
	if (button == RMB)
		game->mouse.rmb_pressed = 0;
	return (0);
}
