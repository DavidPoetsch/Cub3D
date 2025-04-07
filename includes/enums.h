/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:46 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/07 14:27:19 by lstefane         ###   ########.fr       */
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

enum	e_player_state
{
	DEAD,
	ALIVE,
};

enum	e_map_objects
{
	OPEN,
	WALL,
	PLAYER,
	DOOR,
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

#endif //ENUMS_H