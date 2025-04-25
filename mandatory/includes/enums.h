/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:46 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 14:43:30 by dpotsch          ###   ########.fr       */
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

enum	e_map_objects
{
	OPEN = '0',
	WALL = '1',
	PLAYER_N = 'N',
	PLAYER_E = 'E',
	PLAYER_S = 'S',
	PLAYER_W = 'W',
};

#endif //ENUMS_H