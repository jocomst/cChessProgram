# Makefile for Chess PGN Reader

# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -g # Added -g flag for debugging symbols

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include
TEST_DIR = tests

# Source and object files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(filter-out $(SRC_DIR)/main.o, $(SOURCES:.c=.o))
EXECUTABLE = $(BIN_DIR)/chess-pgn-reader

# Test sources and objects
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_EXECUTABLES = $(TEST_SOURCES:$(TEST_DIR)/%.c=$(BIN_DIR)/%)

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Compiling source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test targets
.PHONY: tests
tests: $(TEST_EXECUTABLES)

$(BIN_DIR)/%: $(TEST_DIR)/%.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -lcunit

# Running tests
.PHONY: run-tests
run-tests: tests
	@echo "Running tests..."
	@for test in $(TEST_EXECUTABLES); do \
		./$$test; \
	done

# Debugging with gdb
.PHONY: debug
debug: $(EXECUTABLE)
	gdb $(EXECUTABLE)

# Cleaning up
clean:
	rm -f $(SRC_DIR)/*.o $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLES)

# Phony targets
.PHONY: all clean debug

