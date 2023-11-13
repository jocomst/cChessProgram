# Makefile for Chess PGN Reader

# Compiler and flags
CC = gcc
CFLAGS = -Iinclude

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Source and object files
SOURCES = $(SRC_DIR)/chess_display.c $(SRC_DIR)/chess_logic.c $(SRC_DIR)/chess_reader.c $(SRC_DIR)/main.c $(SRC_DIR)/openings.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = $(BIN_DIR)/chess-pgn-reader

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Compiling source files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning up
clean:
	rm -f $(SRC_DIR)/*.o $(EXECUTABLE)

# Phony targets
.PHONY: all clean
