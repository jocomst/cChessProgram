#include "chess_display.h"
#include "game_controller.h"


int main() {

    Chessboard chessboard;
    initialize_board(&chessboard); 
    display_board(&chessboard);     // This function is still in the chess_display.c file
    start_game_loop(&gameState);

    return 0;
}
