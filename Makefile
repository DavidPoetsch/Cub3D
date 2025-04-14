# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:01:19 by lstefane          #+#    #+#              #
#    Updated: 2025/04/14 10:52:00 by lstefane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
UPPERCASE_NAME := $(shell echo $(NAME) | tr '[:lower:]' '[:upper:]')

# Directories
SRC_DIR := srcs
BUILD_DIR := build
INC_DIR := includes
LIB_DIR := libs
LIBFT_DIR := $(LIB_DIR)/libft

# Source files
-include source_files.mk
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS_FILES))
DEPS := $(OBJS:.o=.d)

# Libraries
LIB_FILES := $(LIBFT_DIR)/libft.a
LIBRARIES := $(LIBFT_DIR)
LIB_INCLUDES := $(LIBFT_DIR)/includes

# Compiler
CC := cc
RM := rm -f

# Flags
CPPFLAGS := $(addprefix -I, $(INC_DIR) $(LIB_INCLUDES)) -MMD -MP
CFLAGS := -Wall -Wextra -Werror $(CPPFLAGS)
LDFLAGS := $(addprefix -L, $(LIBRARIES))
LDLIBS := -lft -lmlx -lXext -lX11 -lm

# Debug / Sanitize / Valgrind
CDEBUG := -g
SAN_A_FLAGS := -g -fsanitize=address
VALG := valgrind
VALG_FLAGS := --trace-children=yes --errors-for-leak-kinds=all \
			  --leak-check=full --read-var-info=yes \
			  --show-error-list=yes --show-leak-kinds=all \
			  --track-origins=yes

# Color (optional)
-include config.mk

# Arguments
ARGS ?=

# ---------------------------------- BUILD ------------------------------------ #

all: $(NAME)

$(NAME): $(LIB_FILES) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN_BOLD)$(UPPERCASE_NAME) - COMPLETE$(RESET)"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ \
	&& echo "$(GREEN)DONE$(RESET)" \
	|| echo "$(RED_BOLD)ERROR: $<$(RESET)"


# --------------------------------- CLEANING ---------------------------------- #

clean:
	@$(RM) $(OBJS) $(DEPS)
	@rm -rf $(BUILD_DIR)
	@echo "$(YELLOW)removed build directory and object files$(RESET)"
	@echo "$(YELLOW)CLEAN - DONE$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)removed $(NAME) binary$(RESET)"
	@echo "$(ORANGE_BOLD)FCLEAN - DONE$(RESET)"

re: fclean all

# --------------------------------- RUNNING ---------------------------------- #

ARGS="./test/maps/test.cub"
run: $(NAME)
	@./$(NAME) $(ARGS)

runv: debug
	@$(VALG) $(VALG_FLAGS) ./$(NAME) $(ARGS)

runsa: sana
	@./$(NAME) $(ARGS)

# ---------------------------------- MODES ------------------------------------ #

debug: CFLAGS += $(CDEBUG)
debug: fclean $(NAME)
	@echo "$(YELLOW_BOLD)DEBUG BUILD COMPLETE$(RESET)"

sana: CFLAGS += $(SAN_A_FLAGS)
sana: fclean $(NAME)
	@echo "$(ORANGE_BOLD)SANITIZE (ADDRESS) BUILD COMPLETE$(RESET)"

# -------------------------------- LIBRARIES ---------------------------------- #
$(LIB_FILES):
	@$(MAKE) -C $(LIBFT_DIR)

# ---------------------------------- MISC ------------------------------------- #

-include $(DEPS)

.PHONY: all clean fclean re run runv sana debug bonus
