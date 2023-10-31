#include "chess_display.h"
#include <stdio.h>
#include <string.h>

void initialize_board(Chessboard *chessboard) {
    char initial_board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    memcpy(chessboard->board, initial_board, sizeof(initial_board));
}

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

void display_game(const char *pgn) {
    Chessboard chessboard;
    initialize_board(&chessboard);
    // ... (rest of the function)
}
