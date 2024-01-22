// game_controller.c
#include <stdlib.h>
#include "game_controller.h"
#include "chess_logic.h"
#include "chess_display.h"
#include "chess_reader.h"
#include <stdio.h>
#include <ctype.h> // For tolower function

void start_game_loop(GameState *gameState) {
    // Ensure the game starts with white's turn
    gameState->currentPlayer = WHITE;

    while (gameState->status == ONGOING) {
        display_board(gameState); // Display the board

        // Debugging: print out the current player
        printf("Current player: %s\n", gameState->currentPlayer == WHITE ? "White" : "Black");

        char moveInput[MAX_MOVE_NOTATION_LEN];
        if (read_player_move(moveInput, gameState)) {
            Move move = parse_standard_notation(moveInput);

            // Verify that the piece color matches the current player
            ChessPiece *piece = &gameState->chessboard.board[move.startRow][move.startCol].piece;
            if (piece->color == gameState->currentPlayer) {
                apply_move(gameState, &move);  // Apply the move
                switch_player(gameState);      // Switch the player
            } else {
                printf("It's not your turn to move that piece. Please enter a move for the %s pieces.\n", 
                       gameState->currentPlayer == WHITE ? "white" : "black");
                continue; // Skip to the next iteration of the loop
            }
        } else {
            // Handle 'quit' or other non-move input
            break;
        }

        // Check for endgame conditions
        // ...
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



