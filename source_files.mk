# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:12:54 by lstefane          #+#    #+#              #
#    Updated: 2025/04/09 09:18:15 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_FILES =	srcs/main.c

# Controls
SRCS_FILES += srcs/controls/controls.c \
							srcs/controls/events/destroy_event.c \
							srcs/controls/events/key_press_event.c \
							srcs/controls/events/key_release_event.c \
							srcs/controls/events/mouse_move_event.c \
							srcs/controls/hooks/key_hooks.c \
							srcs/controls/hooks/mouse_hooks.c \

# Math utils
SRCS_FILES += srcs/math/vec_add.c \
							srcs/math/vec_rot_z.c \
							srcs/math/vec_set.c \
							srcs/math/vec_sub.c \

# Mlx utils
SRCS_FILES += srcs/mlx_utils/free_mlx.c \
							srcs/mlx_utils/init_mlx.c \

# Map Parsing
SRCS_FILES += srcs/parsing/parsing.c \

# utils
SRCS_FILES += srcs/utils/init_game.c \
							srcs/utils/result.c \

# Render
SRCS_FILES += srcs/render/render.c \
							srcs/render/get_delta_seconds.c
