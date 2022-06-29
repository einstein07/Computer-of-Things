CC = em++
INC_DIR = include
SRC_DIR = src
OBJ_DIR = Object
CFLAGS  = -c -Wall -I.
SRCS = $(SRC_DIR)/ComputerOfThings.cpp 
OBJS = $(OBJ_DIR)/ComputerOfThings.o
EXECUTABLE=ComputerOfThings.mjs



DEPS = $(INC_DIR)/*.h


all:$(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE):$(OBJS)
	$(CC) $(OBJS) -o $@
	-s ENVIRONMENT='web' \
	-s SINGLE_FILE=1 \
	-s WASM=1 \
	-s EXPORT_NAME='createModule' \
	-s USE_ES6_IMPORT_META=0 \
	-s EXPORTED_FUNCTIONS='["_process_work_packages", "_malloc", "_free"]' \
	-s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' 
	-O3

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ComputerOfThings.o: $(DEPS)
