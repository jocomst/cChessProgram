#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "chess_reader.h"

// Function to read the player's move in algebraic notation
void read_player_move(char *input) {
    printf("Enter your move (in algebraic notation): ");
    // Assuming that the input will not exceed 99 characters.
    // fgets reads up to sizeof(input) - 1 characters and null-terminates the string.
    if (fgets(input, 100, stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }
    
    // Optional: Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}
