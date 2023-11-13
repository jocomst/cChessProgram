#include "chess_display.h"
#include <stdio.h>


int main() {
    char sample_pgn[] = "1.e4 e5 2.Nf3 Nc6 3.Bc4 Bc5";  // Example PGN

    Chessboard chessboard;
    initialize_board(&chessboard);  // This function is still in the chess_display.c file
    display_board(&chessboard);     // This function is still in the chess_display.c file

    return 0;
}
