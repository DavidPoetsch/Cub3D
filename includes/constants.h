/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/16 15:19:35 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WIN_NAME "Cub3D"

# define CMP_OK 0

# define WIDTH 960  // 1920
# define HEIGHT 480 // 1080

# define TILESIZE 8

# define INTERACT_DIST 1

# define PLAYER_COL 0x880088
# define PLAYER_SIZE 8
# define MOVE_SPEED 0.05
# define MOUSE_MOVE_SPEED 12000
# define ROTATION_SPEED 1.0
# define WALL_DIST_MIN 0.1
# define M_WIDTH 100
# define M_HEIGHT 100
# define MAP_SIZE 20
# define MAP_PADDING 2
# define MAP_BACKGROUND 0x000000
# define MAP_DOOR_COLOR 0xFF0000

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

#endif // CONSTANTS_H
