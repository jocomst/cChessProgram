#include "chess_display.h"
#include "chess_game_state.h"
#include "game_controller.h"
#include <stdio.h>



int main() {

    Chessboard chessboard;
    
    // 1. Display the ASCII art intro screen.
    display_intro_screen();
    
     // Create a GameState instance
    GameState gameState;
    initialize_game_state(&gameState); // Initialize the game state with default values or setup.
    
     // 2. Prompt the user to start the game or quit.
    bool gameStarted = prompt_start_game(&gameState);
    
    if (gameStarted) {
        // 3. If the user starts the game, display the chessboard and proceed.
        initialize_board(&chessboard); 
        display_board(&chessboard);
        // Continue with game loop or next step of the game.
    } else {
        // If the user chooses to quit, end the program.
        printf("Exiting the game. Thank you for playing!\n");
    }

    return 0;
}
