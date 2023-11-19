#ifndef CHESS_LOGIC_H
#define CHESS_LOGIC_H

#include "chess_game_state.h"

// Enum to represent the types of chess pieces
typedef enum {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    EMPTY   // To represent an empty square
} PieceType;

// Structure to represent a chess piece
typedef struct {
    PieceType type;
    char color; // 'W' for white, 'B' for black
    int has_moved; // 0 for no, 1 for yes - useful for pawns and castling logic
} ChessPiece;

// Function declarations
void initialize_pieces(Chessboard *chessboard);
void move_piece(Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col);
int is_move_legal(const Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col);
// Add more function declarations as needed for your chess logic

#endif // CHESS_LOGIC_H