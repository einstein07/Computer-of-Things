CC = emcc
SRC_DIR = src
SRCS = $(SRC_DIR)/ComputerOfThings.cpp  
OBJS = $(OBJ_DIR)/ComputerOfThings.o
EXECUTABLE=ComputerOfThings.mjs


all:$(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE):$(SRCS)
	$(CC) --no-entry $(SRCS) -o $(EXECUTABLE) \
	-s ENVIRONMENT='web' \
	-s WASM=1 \
	-s MODULARIZE=1 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s EXPORT_NAME='createModule' \
	-s USE_ES6_IMPORT_META=0 \
	-s EXPORTED_FUNCTIONS='["_process_work_packages", "_deserializeWorkpackage", "_malloc", "_free"]' \
	-s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
	-O3

