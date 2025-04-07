# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 12:01:19 by lstefane          #+#    #+#              #
#    Updated: 2025/04/07 12:17:58 by lstefane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		cub3D
UPPERCASE_NAME = $(shell echo $(NAME) | tr '[:lower:]' '[:upper:]')

# Flags
CFLAGS := -Wall -Werror -Wextra -Iincludes
MLXFLAGS = -lmlx -lXext -lX11 -lm
CDEBUG := -g
VALG := valgrind
VALG_FLAGS := --trace-children=yes \
							--errors-for-leak-kinds=all \
							--leak-check=full \
							--read-var-info=yes \
							--show-error-list=yes \
							--show-leak-kinds=all \
							--track-origins=yes
SAN_A_FLAGS := -g -fsanitize=address

# Files
-include source_files.mk
OBJS =		$(SRCS_FILES:.c=.o)
RM =			rm -f
CC =			cc

# Color
-include config.mk

# Args
ARGS ?=

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN_BOLD)$(UPPERCASE_NAME) - COMPLETE $(RESET)"

%.o: %.c
		@echo "$(BLUE)compiling $<$(RESET)"
		@$(CC) $(CFLAGS) -c $< -o $@ \
		&& echo "$(GREEN)DONE$(RESET)" \
		|| echo "$(RED_BOLD)ERROR: $<$(RESET)"

clean:
		@$(RM) $(OBJS)
		@echo "$(YELLOW)removing *.o files$(RESET)"
		@echo "$(YELLOW)CLEAN - DONE$(RESET)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(YELLOW)removing $(NAME)$(RESET)"
		@echo "$(ORANGE_BOLD)FCLEAN - DONE$(RESET)"

re: fclean all

# make and run
run: $(NAME)
		@./$(NAME) $(ARGS)

# Run with valgrind 
runv: debug
		@$(VALG) $(VALG_FLAGS) ./$(NAME) $(ARGS)

# Run with sanitize address
runsa: sana
		@./$(NAME) $(ARGS)

# Debug Rule
debug: CFLAGS += $(CDEBUG)
debug: fclean $(NAME)
		@echo "$(YELLOW_BOLD)DEBUG BUILD COMPLETE $(RESET)"

# Sanitize Address Rule
sana: CFLAGS += $(SAN_A_FLAGS)
sana: fclean $(NAME)
		@echo "$(ORANGE_BOLD)SANITIZE (ADDRESS) BUILD COMPLETE $(RESET)"

.PHONY: all clean fclean re debug