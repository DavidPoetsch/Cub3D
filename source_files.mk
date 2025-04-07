# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:12:54 by lstefane          #+#    #+#              #
#    Updated: 2025/04/07 13:04:01 by lstefane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_FILES =	srcs/main.c

# Controls
SRCS_FILES += srcs/controls/controls.c \

# Map Parsing
SRCS_FILES += srcs/parsing/parsing.c \

# Render
SRCS_FILES += srcs/render/render.c