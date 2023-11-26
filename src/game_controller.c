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

