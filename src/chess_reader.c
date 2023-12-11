#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "chess_reader.h"

// Function to read the player's move in algebraic notation
#include "chess_reader.h"

// Function to read the player's move in algebraic notation and validate it
void read_player_move(char *input) {
    bool validInput = false;
    while (!validInput) {
        printf("Enter your move (in algebraic notation): ");

        // fgets reads up to sizeof(input) - 1 characters and null-terminates the string.
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
            printf("Invalid move format. Please enter a move in algebraic notation (e.g., 'e4', 'Nf3').\n");
        }
    }
}


bool parse_algebraic_notation(const char *input, Move *move) {
    // Clear existing notation
    memset(move->notation, 0, MAX_MOVE_NOTATION_LEN);

    // Validate and copy the input into the move notation
    // Example validation: Check if the input is a valid algebraic notation
    if (isValidNotation(input)) {  // You need to implement isValidNotation
        strncpy(move->notation, input, MAX_MOVE_NOTATION_LEN - 1);
        return true;
    } else {
        return false;
    }
}

bool isValidNotation(const char *notation) {
    int len = strlen(notation);

    // Basic validation: Length check
    if (len < 2 || len > 6) {
        return false;
    }

    // Validating different types of moves
    if (islower(notation[0])) {  // Pawn moves and captures (e.g., "e4", "exd5")
        if (len == 2 && isdigit(notation[1])) {
            return true;  // Simple pawn move
        }
        if (len == 4 && notation[1] == 'x' && 
            islower(notation[2]) && isdigit(notation[3])) {
            return true;  // Pawn capture
        }
        if (len == 5 && notation[1] == 'x' && 
            islower(notation[2]) && isdigit(notation[3]) && notation[4] == '+') {
            return true;  // Pawn capture with check
        }
    } else if (strchr("KQBNR", notation[0])) {  // Piece moves (e.g., "Nf3")
        if (len == 3 && islower(notation[1]) && isdigit(notation[2])) {
            return true;  // Simple piece move
        }
        if (len == 4 && notation[1] == 'x' && 
            islower(notation[2]) && isdigit(notation[3])) {
            return true;  // Piece capture
        }
        if (len == 5 && notation[1] == 'x' && 
            islower(notation[2]) && isdigit(notation[3]) && notation[4] == '+') {
            return true;  // Piece capture with check
        }
        if (len == 6 && notation[1] == 'x' && 
            islower(notation[2]) && isdigit(notation[3]) && notation[4] == '=' &&
            strchr("QBNR", notation[5])) {
            return true;  // Pawn promotion with capture
        }
    }

    // Castling (e.g., "O-O", "O-O-O")
    if ((strcmp(notation, "O-O") == 0) || (strcmp(notation, "O-O-O") == 0)) {
        return true;
    }

    // If none of the conditions are met, return false
    return false;
}
