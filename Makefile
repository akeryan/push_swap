# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:55:14 by akeryan           #+#    #+#              #
#    Updated: 2023/10/27 10:12:49 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin
LIBFT_DIR = libft
FLAGS = -g -Wall -Wextra -Werror
PUSH_SWAP_H = include/$(NAME).h

#List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

#List of object files to build
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

#Executable name
EXECUTABLE = $(BIN_DIR)/$(NAME)

all: libft_build $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) 
	$(CC) $(FLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(PUSH_SWAP_h) | $(BUILD_DIR)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

libft_build:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(EXECUTABLE)

re: clean all

.PHONY: all clean fclean re
