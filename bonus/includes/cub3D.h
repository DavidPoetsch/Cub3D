/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:11:12 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 16:08:41 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//STD - HEADER
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>

//CUSTOM - HEADER
# include "constants.h"
# include "structs.h"
# include "controls.h"
# include "debug.h"
# include "error_handling.h"
# include "enums.h"
# include "keys.h"
# include "libft.h"
# include "debug.h"
# include "math_utils.h"
# include "player.h"
# include "render.h"
# include "mlx_utils.h"
# include "multiplayer.h"
# include "parsing.h"
# include "utils.h"
# include "mlx.h"
# include "X11/X.h"

#endif // CUB3d_H
