#include "chess_display.h"
#include <stdio.h>

void display_board(Chessboard *chessboard) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessboard->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char sample_pgn[] = "1.e4 e5 2.Nf3 Nc6 3.Bc4 Bc5";  // Example PGN

    Chessboard chessboard;
    initialize_board(&chessboard);  // This function is still in the chess_display.c file
    display_board(&chessboard);     // This will now call the function you defined in this file

    return 0;
}
