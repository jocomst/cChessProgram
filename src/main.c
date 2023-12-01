#include "chess_display.h"
#include "chess_game_state.h"
#include "game_controller.h"


int main() {

    Chessboard chessboard;
    GameState gameState;
    // 1. Display the ASCII art intro screen.
    display_intro_screen();
    
    initialize_board(&chessboard); 
    display_board(&chessboard);     // This function is still in the chess_display.c file
    initialize_game_state(&gameState);
    prompt_start_game(&gameState);

    return 0;
}
