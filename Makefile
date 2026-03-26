# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 15:24:18 by adpinhei          #+#    #+#              #
#    Updated: 2026/03/26 18:30:42 by clumertz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

###############################################################################
#                            Target and Compiler                              #
###############################################################################
NAME := cub3D

CC := cc

PARAM :=

###############################################################################
#                                mlx Flags                                    #
###############################################################################
MLX_PATH := ./minilibx-linux
MLX_LIB := $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS := -L$(MLX_PATH) -lmlx -lXext -lX11

###############################################################################
#                                    Flags                                    #
###############################################################################
CFLAGS := -Wall -Wextra -Werror -g -Iincludes -I$(MLX_PATH)
LIBS := -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

###############################################################################
#                                    vpath                                    #
###############################################################################
vpath %.h includes
vpath %.c src error

###############################################################################
#                              Builds' Directory                              #
###############################################################################
BUILD_DIR := build

###############################################################################
#                               Source Files                                  #
###############################################################################
SRC_FILES := parse.c main.c get_next_line.c str_utils.c error.c init.c parse_map.c parse_conf.c render.c player.c draw.c draw_utils.c

###############################################################################
#                               Object Files                                  #
###############################################################################
OBJ_FILES := $(SRC_FILES:%.c=$(BUILD_DIR)/%.o)

###############################################################################
#                                 Includes                                    #
###############################################################################
INCLUDES := cub3d.h game.h structs.h

###############################################################################
#                                Debug Flags                                  #
###############################################################################
gdb: CFLAGS += -g
leak: CFLAGS += -fsanitize=address,undefined -g

###############################################################################
#                                Basic Rules                                  #
###############################################################################
.PHONY: all clean fclean re valgrind norm gdb leak

all: $(VALGRINDRC) $(BUILD_DIR) $(MLX_LIB) $(NAME)

###############################################################################
#                               Create ./build                                #
###############################################################################
$(BUILD_DIR):
	@mkdir -p $@
	@echo "$(GREEN)Creating$(RESET) $(BUILD_DIR)"
	@echo "$(GREEN)Compiled objects$(RESET)"

###############################################################################
#                        Compile objects into /build                          #
###############################################################################
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

###############################################################################
#                               Compile libmlx                                #
###############################################################################
$(MLX_LIB):
	@make --no-print-directory -C $(MLX_PATH)

###############################################################################
#                               Build executable                              #
###############################################################################
$(NAME): $(OBJ_FILES) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $@
	@echo "$(YELLOW)Compiled$(RESET) $(NAME)"

###############################################################################
#                                Debug Rules                                  #
###############################################################################
norm:
	@norminette -R CheckForbiddenSourceHeader

valgrind: $(NAME)
	@echo "$(YELLOW)Valgrind Report$(RESET)"
	@valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--suppressions=mlx.supp \
	./$(NAME) $(PARAM)

gdb: $(NAME)
	@gdb --tui --args ./$(NAME) $(PARAM)

leak: $(NAME)
	@echo "$(YELLOW)Running with sanitizers (adress, leak, undefined)$(RESET)"
	@./$(NAME) $(PARAM)

###############################################################################
#                                  Clean up                                   #
###############################################################################
clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(BLUE)Cleaned object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Cleaned executables$(RESET) $(NAME)"

re: fclean all

###############################################################################
#                                    Help                                     #
###############################################################################
help:
	@echo "$(YELLOW)Available targets:$(RESET)"
	@echo "  all           - Build the mandatory executable"
	@echo "  clean         - Remove object files"
	@echo "  fclean        - Remove all built files"
	@echo "  re            - Clean and rebuild everything"
	@echo "  norm          - Run norminette checks"
	@echo "  valgrind      - Run valgrind on mandatory"
	@echo "  gdb           - Start gdb on mandatory"
	@echo "  leak          - Start LSan for memory leaks"

###############################################################################
#                               Color Codes                                   #
###############################################################################
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

BLUE = \033[1;34m

RESET = \033[0m
