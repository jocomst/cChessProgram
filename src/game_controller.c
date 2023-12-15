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
	char moveInput[MAX_MOVE_NOTATION_LEN];

	read_player_move(moveInput, &gameState);
            // Further processing of the move

            // ...
        // Check for endgame conditions
    }
    // Display end of game message
}

bool prompt_start_game(GameState *gameState) {
    char input[100];
    while (true) {  // Use an infinite loop and break out based on conditions
        printf("\033[2K\r");  // Clear the line and carriage return
        printf("Press 's' to start the game or 'q' to quit: ");
        if (fgets(input, sizeof(input), stdin)) {
            if (tolower(input[0]) == 's') {
                printf("\033[H\033[J");  // Clear the screen
                return true;  // User chose to start the game
            } else if (tolower(input[0]) == 'q') {
                return false;  // User chose to quit the game
            } else {
                printf("Invalid input. Please try again.\n");
                // No need for a return statement here since the loop will continue
            }
        } else {
            printf("Error reading input. Exiting...\n");
            return false;  // Return false to indicate the game should not proceed
        }
    }
}



