
BUILD_DIR = ./build
SOURCE_DIR = ./src
LIBS_SRC = ./libs/src

COMPILER ?= clang++
CCOMPILER ?= clang


OPS = -g -Wvarargs -Wall -Werror -std=c++23
COPS = -g -Wvarargs -Wall -Werror 
INCLUDE_FLAGS = -I./include -I./libs/include 
LINKER_FLAGS =  -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

OUT = renderer

CPP_FILES = $(shell find $(SOURCE_DIR) -name '*.cpp')
C_LIBS_FILES = $(shell find $(LIBS_SRC) -name '*.c')

OBJ_FILES  = $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/src/%.o, $(CPP_FILES))
COBJ_FILES  = $(patsubst $(LIBS_SRC)/%.c, $(BUILD_DIR)/libs/%.o, $(C_LIBS_FILES))


.PHONY: all clean test 

all: renderer
	$(BUILD_DIR)/$(OUT)

debug: renderer
	gdb $(BUILD_DIR)/$(OUT)

clean:
	rm -rf $(BUILD_DIR)/*

renderer: $(OBJ_FILES) $(COBJ_FILES)
	$(COMPILER) -o $(BUILD_DIR)/$(OUT) $(OBJ_FILES) $(COBJ_FILES) $(DEFINES) $(INCLUDE_FLAGS) $(LINKER_FLAGS) $(OPS)


$(BUILD_DIR)/src/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(@D)
	$(COMPILER) $(OPS) -c $< -o $@ $(DEFINES) $(INCLUDE_FLAGS)

$(BUILD_DIR)/libs/%.o: $(LIBS_SRC)/%.c
	mkdir -p $(@D)
	$(CCOMPILER) $(COPS) -c $< -o $@ $(DEFINES) $(INCLUDE_FLAGS)	