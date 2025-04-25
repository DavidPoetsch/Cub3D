/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:55:47 by dpotsch           #+#    #+#             */
/*   Updated: 2025/04/24 14:34:50 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_door	*get_door(t_game *game, t_pos pos)
{
	int		i;
	t_door	*doors;
	t_door	*door;

	i = 0;
	doors = game->map.doors;
	while (i < game->map.door_count)
	{
		door = &doors[i];
		if (door->pos_closed.x == pos.x && door->pos_closed.y == pos.y)
		{
			door->state = CLOSED;
			return (door);
		}
		else if (door->pos_opened.x == pos.x && door->pos_opened.y == pos.y)
		{
			door->state = OPENED;
			return (door);
		}
		i++;
	}
	return (NULL);
}

static void	update_map(t_game *game, bool send_update, t_pos pos, char value)
{
	game->map.arr[pos.y][pos.x] = value;
	if (send_update)
		send_map_update(game, pos.x, pos.y, value);
}

void	move_door(t_game *game, t_pos pos, bool send_update)
{
	t_door	*door;

	door = get_door(game, pos);
	if (door == NULL)
		return ;
	if (door->state == CLOSED)
	{
		update_map(game, send_update, door->pos_closed, '0');
		update_map(game, send_update, door->pos_opened, 'D');
	}
	else
	{
		move_player_if_in_door(game, door->pos_closed);
		update_map(game, send_update, door->pos_opened, '1');
		update_map(game, send_update, door->pos_closed, 'D');
	}
}
