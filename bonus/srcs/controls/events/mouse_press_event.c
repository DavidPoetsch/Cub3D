/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:19:54 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 16:40:49 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_press_event(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == LMB)
		game->mouse.lmb_pressed = 1;
	if (button == MMB)
		game->mouse.mmb_pressed = 1;
	if (button == RMB)
		game->mouse.rmb_pressed = 1;
	return (0);
}
