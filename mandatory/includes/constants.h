/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:55 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/28 09:15:21 by lstefane         ###   ########.fr       */
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

# define MOVE_SPEED 6
# define ROTATION_SPEED 100
# define WALL_DIST_MIN 0.1

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
