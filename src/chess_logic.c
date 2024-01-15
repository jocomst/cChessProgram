#include "chess_display.h"
#include "chess_reader.h"
#include <string.h>
#include <stdlib.h>

bool is_square_occupied(const GameState *gameState, const Move *move) {
    int row = move->startRow;
    int col = move->startCol;

    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        return gameState->chessboard.board[row][col].piece.type != EMPTY;
    }
    return false; // Return false if coordinates are out of bounds
}

bool has_piece_moved(const GameState *gameState, const Move *move) {
    const ChessPiece *piece = &gameState->chessboard.board[move->startRow][move->startCol].piece;
    return piece->has_moved;
}

void apply_move(GameState *gameState, const Move *move) {
    Chessboard *chessboard = &gameState->chessboard;
    ChessPiece *startSquare = &chessboard->board[move->startRow][move->startCol].piece;
    ChessPiece *endSquare = &chessboard->board[move->endRow][move->endCol].piece;

    // Move the piece
    *endSquare = *startSquare;

    // Mark the start square as empty
    startSquare->type = EMPTY;
    startSquare->color = NONE;

    // Mark the piece as having moved
    endSquare->has_moved = true;

    // TODO: Add any special move logic (e.g., en passant, castling, promotion)
}

bool pawn_move(GameState *gameState, const Move *move) {
    // Check if the moving piece is a pawn
    ChessPiece *piece = &gameState->chessboard.board[move->startRow][move->startCol].piece;
    if (piece->type != PAWN) {
        return false;
    }

    // Check move direction and distance
    int moveDistance = move->endRow - move->startRow;
    if (piece->color == WHITE && moveDistance <= 0) return false; // White pawns move upwards (row number decreases)
    if (piece->color == BLACK && moveDistance >= 0) return false; // Black pawns move downwards (row number increases)
    if (abs(moveDistance) > 2 || (abs(moveDistance) == 2 && piece->has_moved)) return false; // Pawns can move two squares only from starting position

    // Check for capture if the move is diagonal
    if (move->startCol != move->endCol) {
        // Capture logic here...
    }

    // Check for obstruction in case of a two-square move
    if (abs(moveDistance) == 2) {
        // Check path obstruction here...
    }

    // Apply the move
    apply_move(gameState, move);
    return true;
}

