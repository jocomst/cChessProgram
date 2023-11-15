#ifndef CHESS_GAME_STATE_H
#define CHESS_GAME_STATE_H

#include <stdbool.h>
#define BOARD_SIZE 8

typedef struct {
    char piece;
    bool is_occupied;
    // Additional attributes here
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

// Other game state related declarations...

#endif // CHESS_GAME_STATE_H
