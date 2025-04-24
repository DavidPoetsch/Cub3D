# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:12:54 by lstefane          #+#    #+#              #
#    Updated: 2025/04/24 09:52:39 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES =	srcs/main.c

# Controls
SRCS_FILES += srcs/controls/controls.c \
							srcs/controls/events/destroy_event.c \
							srcs/controls/events/key_press_event.c \
							srcs/controls/events/key_release_event.c \
							srcs/controls/events/mouse_move_event.c \
							srcs/controls/events/mouse_press_event.c \
							srcs/controls/events/mouse_release_event.c \
							srcs/controls/hooks/key_hooks.c \
							srcs/controls/hooks/mouse_hooks.c \

# Debug
SRCS_FILES += srcs/debug/debug.c \

# Error Handling
SRCS_FILES += srcs/error_handling/error_handling.c \

# Math utils
SRCS_FILES += srcs/math/vec_add.c \
							srcs/math/vec_rot_z.c \
							srcs/math/vec_set.c \
							srcs/math/vec_sub.c \
							srcs/math/vec_mul.c \
							srcs/math/square.c \

# Mulitplayer
SRCS_FILES += \
							srcs/multiplayer/enqueue_msg.c \
							srcs/multiplayer/handle_game_state.c \
							srcs/multiplayer/init_multiplayer.c \
							srcs/multiplayer/multiplayer.c \
							srcs/multiplayer/receive_msg.c \
							srcs/multiplayer/receive_pos.c \
							srcs/multiplayer/send_map_update.c \
							srcs/multiplayer/send_msgs.c \
							srcs/multiplayer/send_pos.c \
							srcs/multiplayer/set_enemy_dead.c \
							srcs/multiplayer/update_enemy.c \

# Mlx utils
SRCS_FILES += srcs/mlx_utils/free_mlx.c \
							srcs/mlx_utils/draw_area.c \
							srcs/mlx_utils/init_mlx.c \
							srcs/mlx_utils/init_new_img.c \
							srcs/mlx_utils/open_img.c \
							srcs/mlx_utils/put_nbr.c \
							srcs/mlx_utils/put_pixel.c \
							srcs/mlx_utils/put_str.c \
							srcs/mlx_utils/draw_line.c \
							srcs/mlx_utils/move_img_buf.c \

# Map Parsing
SRCS_FILES += srcs/parsing/parsing.c \
							srcs/parsing/assign_base_textures.c \
							srcs/parsing/check_assign_colors.c \
							srcs/parsing/check_player_start.c \
							srcs/parsing/parse_doors.c \
							srcs/parsing/parse_lst_to_arr.c \
							srcs/parsing/parse_map_lst.c \
							srcs/parsing/parse_map.c \
							srcs/parsing/parse_open_textures.c \
							srcs/parsing/parse_sprites.c \
							srcs/parsing/parse_sprites_count.c \
							srcs/parsing/parse_sprites_utils.c \
							srcs/parsing/parse_textures.c \
							srcs/parsing/parse_tex_lst.c \
							srcs/parsing/utils/line_utils.c \

# Player
SRCS_FILES += \
							srcs/player/ammo.c \
							srcs/player/health_pack.c \
							srcs/player/rotate_player.c \
							srcs/player/init_player.c \
							srcs/player/check_interactions.c \
							srcs/player/move_door.c \
							srcs/player/move_player.c \

# utils
SRCS_FILES += \
							srcs/utils/color_utils.c \
							srcs/utils/copy_ray.c \
							srcs/utils/file_utils.c \
							srcs/utils/get_delta_seconds.c \
							srcs/utils/get_time_ms.c \
							srcs/utils/init_game.c \
							srcs/utils/map_utils_2.c \
							srcs/utils/map_utils.c \
							srcs/utils/pixel_utils.c \
							srcs/utils/pos_utils.c \
							srcs/utils/result.c \
							srcs/utils/sem_utils.c \

# Render
SRCS_FILES += srcs/render/render.c \
							srcs/render/animate_sprites.c \
							srcs/render/check_collectables.c \
							srcs/render/draw_background.c \
							srcs/render/draw_game_info.c \
							srcs/render/draw_map.c \
							srcs/render/draw_sprites.c \
							srcs/render/draw_wall.c \
							srcs/render/raycast_2.c \
							srcs/render/raycast.c \
							srcs/render/draw_win_lose.c \
							srcs/render/draw_pistol.c \
							srcs/render/draw_health.c \
