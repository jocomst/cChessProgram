#ifndef CHESS_GAME_STATE_H
#define CHESS_GAME_STATE_H

#include <stdbool.h>
#define BOARD_SIZE 8

typedef struct {
    char piece;
    bool is_occupied;
    char notation[3];  // Additional attribute to store chess notation
    // Additional attributes here
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

// Other game state related declarations...

#endif // CHESS_GAME_STATE_H
