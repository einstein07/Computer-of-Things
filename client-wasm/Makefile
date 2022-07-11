CC = emcc
SRC_DIR = src
SRCS = $(SRC_DIR)/ComputerOfThings.cpp  
EXECUTABLE=ComputerOfThings.mjs


all:$(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE):$(SRCS)
	$(CC) --no-entry $(SRCS) -o $(EXECUTABLE) \
	-s ENVIRONMENT='web' \
	-s SINGLE_FILE=1 \
	-s WASM=1 \
	-s EXPORT_NAME='createModule' \
	-s USE_ES6_IMPORT_META=0 \
	-s EXPORTED_FUNCTIONS='["_processWorkPackages", "_malloc", "_free"]' \
	-s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "getValue", "AsciiToString"]' \
	-O3

