/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:54:42 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/17 13:55:31 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	multiplayer(t_game *game)
{
	update_player_pos(game);
	read_enemy_pos(game);
}
