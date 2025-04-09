# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:12:54 by lstefane          #+#    #+#              #
#    Updated: 2025/04/09 14:04:27 by lstefane         ###   ########.fr        #
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

# Debug
SRCS_FILES += srcs/debug/debug.c \

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
							srcs/parsing/check_player_start.c \
							srcs/parsing/get_colors.c \
							srcs/parsing/get_textures.c \
							srcs/parsing/parse_lst_to_arr.c \
							srcs/parsing/parse_map_lst.c \
							srcs/parsing/parse_map.c \
							srcs/parsing/parse_textures.c \
							srcs/parsing/utils/line_utils.c \

# utils
SRCS_FILES += srcs/utils/init_game.c \
							srcs/utils/result.c \

# Render
SRCS_FILES += srcs/render/render.c \
							srcs/render/draw_map.c \
							srcs/render/get_delta_seconds.c
