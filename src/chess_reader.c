#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "chess_reader.h"
#include "chess_display.h" // This is where clear_screen and display_board are declared
#include <unistd.h>       // For sleep function on Unix-like systems

// Function to read the player's move in algebraic notation and validate it
void read_player_move(char *input, const GameState *gameState) {
    bool validInput = false;
    while (!validInput) {
        clear_screen(); // Clear the screen before redrawing the chessboard
        display_board(gameState); // Pass the chessboard to display_board

        printf("Enter your move (in algebraic notation): ");
        if (fgets(input, 100, stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
            continue;  // Prompt user to try again
        }

        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Validate input
        validInput = isValidNotation(input);
        if (!validInput) {
            printf("Invalid move format. Please enter a move in standard notation (e.g., 'e2e4', 'g1f3').\n");
            sleep(2); // Give the user time to read the message before the next prompt
        }
    }
}



Move parse_standard_notation(const char *input) {
    Move move;

    // Initialize default values for the Move struct
    move.startRow = -1;
    move.startCol = -1;
    move.endRow = -1;
    move.endCol = -1;

    // Validate and parse the input
    if (strlen(input) == 4 && 
        islower(input[0]) && isdigit(input[1]) && 
        islower(input[2]) && isdigit(input[3])) {

        move.startCol = input[0] - 'a';
        move.startRow = '8' - input[1];
        move.endCol = input[2] - 'a';
        move.endRow = '8' - input[3];
    }

    return move;
}

bool isValidNotation(const char *notation) {
    int len = strlen(notation);

    // Standard chess notation should be exactly 4 characters (e.g., "e2e4")
    if (len != 4) {
        return false;
    }

    // Validate the format: [letter][number][letter][number]
    // e.g., "e2e4"
    if (!islower(notation[0]) || !isdigit(notation[1]) ||
        !islower(notation[2]) || !isdigit(notation[3])) {
        return false;
    }

    // Further checks can be added here for specific rules, like:
    // - The starting square must not be the same as the ending square.
    // - The letter must be between 'a' and 'h', and the number must be between '1' and '8'.

    return true; // The notation is valid
}

