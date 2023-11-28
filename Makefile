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
OBJECTS = $(filter-out $(MAIN_OBJECT), $(SOURCES:.c=.o))
EXECUTABLE = $(BIN_DIR)/chess-pgn-reader
MAIN_OBJECT = $(SRC_DIR)/main.o

# Test sources and objects
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TEST_SOURCES))

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJECT)
	$(CC) $(CFLAGS) $^ -o $@

# Compiling source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test targets
.PHONY: tests
tests: $(TEST_EXECUTABLES)

# Linking the test executables
$(BIN_DIR)/%: $(TEST_DIR)/%.o $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ -lcunit

# Running a specific test or all tests if no specific test is provided
.PHONY: run-test
run-test: $(TEST_EXECUTABLES)
ifdef TEST
	echo "Running specific test: $(TEST)"
	@./$(BIN_DIR)/$(TEST)
else
	@echo "Running all tests..."
	@for test in $(TEST_EXECUTABLES); do \
	./$$test; \
	done
    endif

# Debugging with gdb
.PHONY: debug
debug: $(EXECUTABLE)
	gdb $(EXECUTABLE)

# Cleaning up
clean:
	rm -f $(SRC_DIR)/*.o $(BIN_DIR)/* $(TEST_DIR)/*.o

# Phony targets
.PHONY: all clean debug run-tests

