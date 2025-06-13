# Compiler selection
COMPILER = gcc

# Directory structure
SRC_DIR = src
OBJ_DIR = objects
BIN_DIR = bin

# Source directories (add new directories here)
SRC_DIRS = $(SRC_DIR) $(SRC_DIR)/assign $(SRC_DIR)/str $(SRC_DIR)/insert $(SRC_DIR)/erase $(SRC_DIR)/to_string $(SRC_DIR)/append $(SRC_DIR)/replace # Add more directories as needed

# Compiler flags by build type
DEBUG_FLAGS = -Wall -Wextra -Werror -g -DDEBUG -O0
RELEASE_FLAGS = -O3 -DNDEBUG
DEFAULT_FLAGS =

# Linker flags
LDFLAGS = -O3

# Find all source files
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Generate object files (preserving directory structure)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS)) $(OBJ_DIR)/main.o #f

# Target executable
TARGET = $(BIN_DIR)/program

.PHONY: all clean debug release run git

# Default build (optimized)
all: CFLAGS = $(DEFAULT_FLAGS)
all: $(TARGET)

# Debug build
debug: CFLAGS = $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build
release: CFLAGS = $(RELEASE_FLAGS)
release: $(TARGET)

# Link target
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(COMPILER) $(LDFLAGS) $^ -o $@

# Rule to create object directories before compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -c $< -o $@

# Special rule for main.c
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@

# Create base directories if they don't exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the debug version
run: debug
	./$(TARGET)

git: run
	rm -r $(BIN_DIR) $(OBJ_DIR)
	git add .
	read -p "Enter commit name: " msg && git commit -m "$msg"
	git push
