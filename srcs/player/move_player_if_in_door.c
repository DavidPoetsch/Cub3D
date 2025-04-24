/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_if_in_door.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:24 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:34:01 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	get_directions(t_pos pos_door, t_pos	directions[4])
// {
// 		directions[0] = (t_pos){pos_door.x + 1, pos_door.y};
// 		directions[1] = (t_pos){pos_door.x - 1, pos_door.y};
// 		directions[2] = (t_pos){pos_door.x, pos_door.y + 1};
// 		directions[3] = (t_pos){pos_door.x, pos_door.y - 1};
// }

void	move_player_if_in_door(t_game *game, t_pos pos_door)
{
	t_pos	pos_player;

	pos_player = set_pos(floor(game->player.pos.x), floor(game->player.pos.y));
	if (pos_player.x != pos_door.x || pos_player.y != pos_door.y)
		return ;
	if (is_floor(game->map.arr, pos_door.x + 1, pos_door.y))
		game->player.pos = vec_set(pos_door.x + 1.3, pos_door.y);
	else if (is_floor(game->map.arr, pos_door.x - 1, pos_door.y))
		game->player.pos = vec_set(pos_door.x - 1.3, pos_door.y);
	else if (is_floor(game->map.arr, pos_door.x, pos_door.y + 1.3))
		game->player.pos = vec_set(pos_door.x, pos_door.y + 1.3);
	else if (is_floor(game->map.arr, pos_door.x, pos_door.y - 1))
		game->player.pos = vec_set(pos_door.x, pos_door.y - 1.3);
}
