CC = g++
INC_DIR = include
SRC_DIR = src
OBJ_DIR = Object
CFLAGS  = -c -Wall -I.
SRCS = $(SRC_DIR)/ComputerOfThings.cpp
OBJS = $(OBJ_DIR)/ComputerOfThings.o
# Note: The above will soon get unwieldy.
# The wildcard and patsubt commands will come to your rescue.

DEPS = $(INC_DIR)/*.h
# Note: The above will soon get unwieldy.
# You will soon want to use an automatic dependency generator.


all: $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ComputerOfThings.o: $(DEPS)
