/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:16:32 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/28 09:25:16 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reload_gun(t_game *game)
{
	if (game->player.reloads == 1 && game->player.ammo != AMMO_MAX)
	{
		game->player.reloads = 0;
		game->player.ammo = AMMO_MAX;
	}
}
