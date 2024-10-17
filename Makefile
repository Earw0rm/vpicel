
BUILD_DIR = ./build
SOURCE_DIR = ./src
COMPILER ?= clang++
LIBS_SRC = ./libs

OPS = -g -Wvarargs -Wall -Werror -std=c++23
INCLUDE_FLAGS = -I./include -I./libs/include -I../yasyc/include
LINKER_FLAGS =  -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

OUT = renderer

CPP_FILES = $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJ_FILES  = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/src/%.o, $(CPP_FILES))

.PHONY: all clean test 

all: renderer
	$(BUILD_DIR)/$(OUT)

debug: renderer
	gdb $(BUILD_DIR)/$(OUT)

clean:
	rm -rf $(BUILD_DIR)/*

renderer: $(OBJ_FILES)
	$(COMPILER) -o $(BUILD_DIR)/$(OUT) $(OBJ_FILES) $(DEFINES) $(INCLUDE_FLAGS) $(LINKER_FLAGS) $(OPS)


$(BUILD_DIR)/src/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(@D)
	$(COMPILER) $(OPS) -c $< -o $@ $(DEFINES) $(INCLUDE_FLAGS)