// game_controller.c
#include <stdlib.h>
#include "game_controller.h"
#include "chess_logic.h"
#include "chess_display.h"
#include "chess_reader.h"
#include <stdio.h>
#include <ctype.h> // For tolower function

void start_game_loop(GameState *gameState) {
    while (gameState->status == ONGOING) {
        char moveInput[MAX_MOVE_NOTATION_LEN];

        // Display the board before asking for the player's move
        display_board(gameState);

        // Get the player's move
        if (read_player_move(moveInput, gameState)) {
            // Parse the move from standard notation to the Move structure
            Move move = parse_standard_notation(moveInput);

            // Since we're not checking if the move is legal, apply it directly
            apply_move(gameState, &move);

            // Switch players or perform any additional updates needed after a move
            // ...

            // Update the display after the move
            display_board(gameState);
        } else {
            // Handle 'quit' or other non-move input
            // ...
        }

        // Here you can check for endgame conditions and update gameState->status
        // ...

        // If the game is over, you can break out of the loop
        // if (game_over_condition) {
        //     gameState->status = END_CONDITION;
        //     break;
        // }
    }

    // Display end of game message
    // ...
}

bool prompt_start_game() {
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



