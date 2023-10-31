# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:55:14 by akeryan           #+#    #+#              #
#    Updated: 2023/10/31 18:44:42 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
MOVES_DIR = $(BUILD_DIR)/moves
PARSING_DIR = $(BUILD_DIR)/parsing
PUSH_SWAP_DIR = $(BUILD_DIR)/push_swap
SORT = $(BUILD_DIR)/sort
STACK = $(BUILD_DIR)/stack
DIR_LIST = $(BUILD_DIR) $(MOVES_DIR) $(PARSING_DIR) $(PUSH_SWAP_DIR) $(SORT) $(STACK)
BIN_DIR = bin
LIBFT_DIR = libft
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
PUSH_SWAP_H = include/$(NAME).h

#List of source files
SRCS_1 = $(wildcard $(SRC_DIR)/*.c)
SRCS_2 = $(wildcard $(SRC_DIR)/**/*.c)
SRCS = $(SRCS_1) $(SRCS_2)


#List of object files to build
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

#Executable name
EXECUTABLE = $(BIN_DIR)/$(NAME)

all: libft_build $(EXECUTABLE)

$(BUILD_DIR)%.o: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIS_DIR):
	mkdir -p $(LIS_DIR)

$(MOVES_DIR):
	mkdir -p $(MOVES_DIR)

$(PARSING_DIR):
	mkdir -p $(PARSING_DIR)

$(PUSH_SWAP_DIR):
	mkdir -p $(PUSH_SWAP_DIR)

$(SORT):
	mkdir -p $(SORT)

$(STACK):
	mkdir -p $(STACK)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(EXECUTABLE): $(OBJS) | $(BIN_DIR) 
	$(CC) $(FLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(PUSH_SWAP_h) | $(DIR_LIST)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

libft_build:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -rf $(DIR_LIST)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(EXECUTABLE)
	rm -rf $(BIN_DIR)

re: clean all

.PHONY: all clean fclean re
