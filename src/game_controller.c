// game_controller.c
#include <stdlib.h>
#include "game_controller.h"
#include "chess_display.h"
#include <stdio.h>
#include <ctype.h> // For tolower function

void start_game_loop(GameState *gameState) {
    // The previous game loop logic goes here
    while (gameState->status == ONGOING) {
        // Get input, process moves, update gameState, display the board
        // Check for endgame conditions
    }
    // Display end of game message
}

bool prompt_start_game(GameState *gameState) {
    printf("Press 's' to start the game or 'q' to quit: ");
    char input[100];
    if (fgets(input, sizeof(input), stdin)) {
        if (tolower(input[0]) == 's') {
            return true; // User chose to start the game
        } else if (tolower(input[0]) == 'q') {
            return false; // User chose to quit the game
        } else {
            // If any other input is given, prompt again
            printf("Invalid input. Please try again.\n");
            return prompt_start_game(gameState); // Be cautious of potential stack overflow due to recursion
        }
    } else {
        // If input fails, treat as a quit command
        printf("Error reading input.\n");
        return false;
    }
}

