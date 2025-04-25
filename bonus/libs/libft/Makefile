# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 13:23:49 by dpotsch           #+#    #+#              #
#    Updated: 2025/03/12 13:26:49 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

# Colors
RED    := \033[0;31m
GREEN  := \033[0;32m
YELLOW := \033[0;33m
BLUE   := \033[0;34m
PINK   := \033[0;35m
RESET  := \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_DBG = -Wall -Wextra -Werror -g

BUILD_DIR := ./build

SRCS = srcs/ft_isalpha.c \
       srcs/ft_isdigit.c \
       srcs/ft_isalnum.c \
       srcs/ft_isascii.c \
       srcs/ft_isprint.c \
       srcs/ft_issign.c \
       srcs/ft_strlen.c \
       srcs/ft_memset.c \
       srcs/ft_bzero.c \
       srcs/ft_memcpy.c \
       srcs/ft_memmove.c \
       srcs/ft_strlcpy.c \
       srcs/ft_strlcat.c \
       srcs/ft_strcat.c \
       srcs/ft_toupper.c \
       srcs/ft_tolower.c \
       srcs/ft_strchr.c \
       srcs/ft_strrchr.c \
       srcs/ft_strcmp.c \
       srcs/ft_strncmp.c \
       srcs/ft_strrncmp.c \
       srcs/ft_memchr.c \
       srcs/ft_memcmp.c \
       srcs/ft_strnstr.c \
       srcs/ft_atoi.c \
       srcs/ft_calloc.c \
       srcs/ft_strdup.c \
       srcs/ft_substr.c \
       srcs/ft_strjoin.c \
       srcs/ft_strjoin_4.c \
       srcs/ft_strtrim.c \
       srcs/ft_split.c \
       srcs/ft_itoa.c \
       srcs/ft_strmapi.c \
       srcs/ft_striteri.c \
       srcs/ft_putchar_fd.c \
       srcs/ft_putstr_fd.c \
       srcs/ft_putendl_fd.c \
       srcs/ft_putnbr_fd.c \
       srcs/ft_lstnew.c \
       srcs/ft_lstadd_front.c \
       srcs/ft_lstsize.c \
       srcs/ft_lstlast.c \
       srcs/ft_lstadd_back.c \
       srcs/ft_lstdelone.c \
       srcs/ft_lstclear.c \
       srcs/ft_lstiter.c \
       srcs/ft_lstmap.c \
       srcs/ft_lstswapfirst.c \
       srcs/ft_lstpushfirst.c \
       srcs/ft_lstrotate.c \
       srcs/ft_lstrrotate.c \
       srcs/ft_printf.c \
       srcs/ft_printf_format_check.c \
       srcs/ft_printf_formating.c \
       srcs/ft_printf_output_char.c \
       srcs/ft_printf_output_digit.c \
       srcs/ft_printf_output_hex.c \
       srcs/ft_printf_putnbr_hex.c \
       srcs/ft_printf_putnbr.c \
       srcs/ft_printf_buffer.c \
       srcs/ft_printf_utils.c \
       srcs/ft_printf_utils2.c \
       srcs/get_next_line.c \
       srcs/get_next_line_utils.c \
       srcs/get_next_line_free.c \
       srcs/ft_double_arr_len.c \
       srcs/ft_free_str_lst.c \
       srcs/ft_free_str.c \
       srcs/ft_isspace.c

# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every include dir will need to be passed to CC so it can find header files.
INC_DIRS := ./includes
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA.
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate 'Makefiles' for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# **************************************************************************** #
# * BUILD
all: $(NAME)
	@echo "$(GREEN)Finished '$(NAME)'$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Build    '$(NAME)'$(RESET)"
	@ar rcs $@ $(OBJS)

# Build step for C source
# $(dir ...) is a Make function that extracts the directory of a file path.
# $@ represents the target file in a rule (the file being built).
# $< gets the first prerequiste.
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
ifeq ($(DEBUG),1)
	$(CC) $(CPPFLAGS) $(CFLAGS_DBG) -c $< -o $@
else
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
endif

re: fclean all

bonus: all


# **************************************************************************** #
# * DEBUG
debug: clean all

# **************************************************************************** #
# * CLEAN

clean:
	@echo "$(YELLOW)Clean    '$(NAME)'$(RESET)"
	@rm -rf $(BUILD_DIR)

fclean:
	@echo "$(YELLOW)F-Clean  '$(NAME)'$(RESET)"
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)

.PHONY: all clean fclean re bonus debug

# Include the .d dependencies. The - at the front suppresses the errors of 
# missing dependencies. Initially, all the .d files will be missing, 
# and we don't want those errors to show up.
-include $(DEPS)
