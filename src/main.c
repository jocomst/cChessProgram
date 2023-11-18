#include "chess_display.h"
#include <stdio.h>


int main() {

    Chessboard chessboard;
    initialize_board(&chessboard);  // This function is still in the chess_display.c file
    display_board(&chessboard);     // This function is still in the chess_display.c file

    return 0;
}
