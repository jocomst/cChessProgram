#include "chess_display.h"
#include "chess_reader.h"
#include <string.h>

void apply_move(Chessboard *chessboard, const char *move) {
    // TODO: Implement function to apply a chess move to the board.
}

bool is_square_occupied(const GameState *gameState, const Move *move) {
    int row = move->startRow;
    int col = move->startCol;

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        return gameState->chessboard.board[row][col].piece.type != EMPTY;
    }
    return false; // Return false if coordinates are out of bounds
}
