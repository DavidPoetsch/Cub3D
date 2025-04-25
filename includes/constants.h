/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/25 12:55:42 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WIN_NAME "Cub3D"

# define CMP_OK 0

// 1920 x 960 is full window
// 960 x 480 is small window

# define WIDTH 1200
# define HEIGHT 600

# define MAP_MAX 300

# define INTERACT_DIST 1

# define PLAYER_COL 0x00FF44
# define PLAYER_SIZE 8
# define MOVE_SPEED 6
# define MOUSE_MOVE_SPEED 12
# define ROTATION_SPEED 1.5
# define WALL_DIST_MIN 0.1
# define M_WIDTH 100
# define M_HEIGHT 100

# define MAP_TILE_SIZE 14
# define MAP_TILES 9
# define MAP_PADDING 2

# define MAP_BACKGROUND 0x000000
# define MAP_DOOR_COLOR 0xFF0000
# define MAP_ENEMY_COL 0x0000FF

# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define BLUE "\001\033[0;34m\002"
# define PINK "\001\033[0;35m\002"
# define RESET "\001\033[0m\002"

# define BOLD "\001\033[1m\002"
# define RED_BOLD "\001\033[1;31m\002"
# define GREEN_BOLD "\001\033[1;32m\002"
# define YELLOW_BOLD "\001\033[1;33m\002"
# define BLUE_BOLD "\001\033[1;34m\002"
# define PINK_BOLD "\001\033[1;35m\002"

// you can see fonts in terminal with cmd 'xlsfonts'
# define FONT1 "-misc-fixed-bold-r-normal--13-100-100-100-c-70-iso8859-1"
# define FONT2 "-misc-fixed-bold-r-normal--18-120-100-100-c-90-iso8859-9"

# define SEM_FILE_LOCK "/semaphore_filelock"

# define F_SND_MSG "./test/cub_multiplayer/send_msg.txt"
# define F_RCV_MSG "./test/cub_multiplayer/receive_msg.txt"
# define F_SND_POS "./test/cub_multiplayer/send_pos.txt"
# define F_RCV_POS "./test/cub_multiplayer/receive_pos.txt"

# define RESTART_TIME 7

# define MSG_SIZE 40
# define MSG_LST_SIZE 10

# define PISTOL_ANIM_TIME 0.1

# define AMMO_MAX 8
# define AMMO_HIDE_TIME 5.0

# define ANIM_TIME 200

# define HITMARKER 0.15

# define HEALTH_PACK 50
# define HEALTH_HIDE_TIME 5.0
# define HEALTH_COLOR_1 0
# define HEALTH_COLOR_2 0xFF0000
# define HEALTH_MAX 100

#endif // CONSTANTS_H
