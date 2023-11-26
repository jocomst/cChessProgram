#include "chess_display.h"
#include "chess_game_state.h"
#include "game_controller.h"


int main() {

    Chessboard chessboard;
    GameState gameState;
    initialize_board(&chessboard); 
    display_board(&chessboard);     // This function is still in the chess_display.c file
    initialize_game_state(&gameState);
    start_game_loop(&gameState);

    return 0;
}
