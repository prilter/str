# Compiler selection
COMPILER = gcc

# Directory structure
SRC_DIR = src
OBJ_DIR = objects
BIN_DIR = bin

# Source directories (add new directories here)
SRC_DIRS = $(SRC_DIR) $(SRC_DIR)/str $(SRC_DIR)/erase $(SRC_DIR)/to_string $(SRC_DIR)/replace # Add more directories as needed

# Compiler flags by build type
DEBUG_FLAGS   = -D_GNU_SOURCE -Wall -Wextra -Werror -g -DDEBUG -O0
RELEASE_FLAGS = -D_GNU_SOURCE -O3 -DNDEBUG
DEFAULT_FLAGS = -D_GNU_SOURCE

# Linker flags
LDFLAGS = -O3

# Find all source files
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Exclude example.c for library build
LIB_SRCS = $(filter-out example.c, $(SRCS))

# Generate object files (preserving directory structure)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS)) $(OBJ_DIR)/example.o

# Object files for library (excluding example.o)
LIB_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRCS))

# Target executable
TARGET = $(BIN_DIR)/example

.PHONY: all clean debug release run git lib

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

# Special rule for example.c
$(OBJ_DIR)/example.o: example.c | $(OBJ_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@

# Create base directories if they don't exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) str.o

# Run the debug version
run: debug
	./$(TARGET)

# Build monolithic object file str.o from all sources except example.c
lib: CFLAGS = $(RELEASE_FLAGS)
lib: str.o

str.o: $(LIB_OBJS)
	$(COMPILER) -r $^ -o $@

# Pattern rule for compiling library object files with release flags
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(COMPILER) $(RELEASE_FLAGS) -c $< -o $@

# Commit the source
git: clean
	git add .
	git commit -F -
	git push
