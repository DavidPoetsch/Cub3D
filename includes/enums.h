/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:46 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/22 12:18:22 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum	e_return_values
{
	FAILED = -1,
	SUCCESS = 0,
	ERROR = 1,
};

enum	e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

/* enum	e_sprite_type
{
	OBJECT,
	COLLECT,
}; */

enum	e_map_objects
{
	OPEN = '0',
	WALL = '1',
	PLAYER_N = 'N',
	PLAYER_E = 'E',
	PLAYER_S = 'S',
	PLAYER_W = 'W',
	DOOR = 'D',
	ENEMY = 'X',
	TORCH = 'T',
	AMMO = 'A',
};

enum	e_door_state
{
	CLOSED,
	OPENED,
};

enum	e_mouse_state
{
	M_NO,
	M_LMB,
	M_MMB,
	M_RMB,
	M_UP,
	M_DOWN,
};

enum	e_semaphore_state
{
	SEM_STATE_FAILED,
	SEM_STATE_OPEN,
	SEM_STATE_CLOSED,
	SEM_STATE_UNLINKED,
};

enum e_game_state
{
	GAME_RUNING,
	GAME_RESTART,
};

#endif //ENUMS_H