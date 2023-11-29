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

void prompt_start_game(GameState *gameState) {
    printf("Press 's' to start the game or 'q' to quit: ");
    char input[100];
    if (fgets(input, sizeof(input), stdin)) {
        if (tolower(input[0]) == 's') {
            // If 's' is pressed, start the game loop
            start_game_loop(gameState);
        } else if (tolower(input[0]) == 'q') {
            // If 'q' is pressed, exit the game
            printf("Game not started. Exiting...\n");
            exit(EXIT_SUCCESS);
        } else {
            // If any other input is given, prompt again
            printf("Invalid input. Please try again.\n");
            prompt_start_game(gameState);
        }
    } else {
        // If input fails, exit the game
        printf("Error reading input. Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

