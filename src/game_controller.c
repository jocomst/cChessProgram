// game_controller.c
#include "game_controller.h"
#include "chess_display.h"
#include <stdio.h>

void start_game_loop(GameState *gameState) {
    // The previous game loop logic goes here
    while (gameState->status == ONGOING) {
        // Get input, process moves, update gameState, display the board
        // Check for endgame conditions
    }
    // Display end of game message
}

bool prompt_start_game() {
    printf("Press 's' to start the game or 'q' to quit: ");
    char input[100];
    if (fgets(input, sizeof(input), stdin)) {
        if (input[0] == 's' || input[0] == 'S') {
            return true;
        }
    }
    return false;
}

