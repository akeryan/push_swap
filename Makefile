CC = gcc
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin
LIBFT_DIR = libft
FLAGS = -Wall -Wextra -Werror

#List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

#List of object files to build
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

#Executable name
EXECUTABLE = $(BIN_DIR)/push_swap

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) 
	$(CC) $(FLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft
	

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c| $(BUILD_DIR)
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXECUTABLE)

re: clean all

.PHONY: all clean fclean re