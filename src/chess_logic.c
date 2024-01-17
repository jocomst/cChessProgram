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
    ChessPiece *startPiece = &gameState->chessboard.board[move->startRow][move->startCol].piece;
    if (startPiece->type != PAWN) {
return false;
}

    // Check if the start square is occupied by a pawn of the correct color
if (startPiece->color != gameState->currentPlayer) {
    return false;
}

// Calculate move distance and direction
int moveDistance = move->endRow - move->startRow;
int direction = (startPiece->color == WHITE) ? 1 : -1; // White pawns move up (1), black pawns move down (-1)

// Check for valid forward move
if (move->startCol == move->endCol) {
    if ((moveDistance == direction && !is_square_occupied(gameState, move)) || 
        (moveDistance == 2 * direction && !startPiece->has_moved && 
         !is_square_occupied(gameState, move))) { // Check the square passed over
        // Apply the move
        apply_move(gameState, move);
        return true;
    }
}

// Check for valid capture move
if (abs(move->startCol - move->endCol) == 1 && moveDistance == direction) {
    ChessPiece *endPiece = &gameState->chessboard.board[move->endRow][move->endCol].piece;
    if (endPiece->type != EMPTY && endPiece->color != startPiece->color) {
        // Apply the capture move
        apply_move(gameState, move);
        return true;
    }
}

// Pawn moves are invalid in all other cases
return false;

}

void switch_player(GameState *gameState) {
    if (gameState->currentPlayer == WHITE) {
        gameState->currentPlayer = BLACK;
    } else {
        gameState->currentPlayer = WHITE;
    }
}

