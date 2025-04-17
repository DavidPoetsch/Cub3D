/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:53:17 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/17 14:18:41 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void update_enemy_pos(t_game *game)
{
	return;
	game->enemy.sprite.pos.x = game->enemy.pos.x;
	game->enemy.sprite.pos.y = game->enemy.pos.y;
}