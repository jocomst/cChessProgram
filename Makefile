# Makefile for Chess PGN Reader

# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Itests/include -g # Added -g flag for debugging symbols

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include
TEST_DIR = tests

# Source and object files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(filter-out $(SRC_DIR)/main.o, $(SOURCES:.c=.o))
EXECUTABLE = $(BIN_DIR)/chess-pgn-reader
MAIN_OBJECT = $(SRC_DIR)/main.o

# Test sources and objects
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_EXECUTABLE = $(BIN_DIR)/test_suite

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJECT) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compiling source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compiling test objects
$(TEST_DIR)/%.o: $(TEST_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking the test suite executable
$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(filter-out $(MAIN_OBJECT), $(OBJECTS)) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lcunit

# Running the test suite
.PHONY: run-test
run-test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Debugging with gdb
.PHONY: debug
debug: $(EXECUTABLE)
	gdb $(EXECUTABLE)

# Cleaning up
clean:
	rm -f $(SRC_DIR)/*.o $(BIN_DIR)/* $(TEST_DIR)/*.o

# Phony targets
.PHONY: all clean debug run-test

