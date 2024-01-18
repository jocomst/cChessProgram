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

        display_board(gameState); // Display the board

        if (read_player_move(moveInput, gameState)) {
            Move move = parse_standard_notation(moveInput);

            ChessPiece *piece = &gameState->chessboard.board[move.startRow][move.startCol].piece;
            if (piece->color == gameState->currentPlayer) {
                apply_move(gameState, &move);  // Apply the move
                switch_player(gameState);     // Switch the player
            } else {
                printf("You can only move your own pieces. It's %c's turn.\n", 
                       gameState->currentPlayer == WHITE ? 'W' : 'B');
                // You might want to wait a bit or clear this message in the next screen refresh
                continue; // Skip to the next iteration of the loop
            }

            display_board(gameState); // Update the display after the move
        } else {
            // Handle 'quit' or other non-move input
            // ...
        }

        // Check for endgame conditions

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



