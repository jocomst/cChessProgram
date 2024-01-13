#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

#include <stdbool.h>

// Define BOARD_SIZE if not already defined
#ifndef BOARD_SIZE
#define BOARD_SIZE 8
#endif

// Enum for chess piece types
typedef enum {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} PieceType;

// Enum for player colors
typedef enum {
    WHITE, BLACK, NONE
} PlayerColor;

// Structure to represent a chess piece
typedef struct {
    PieceType type;
    char color; // 'W' for white, 'B' for black
    bool has_moved; 
} ChessPiece;

// Structure to represent a chessboard square
typedef struct {
    ChessPiece piece;
    char notation[3];  // Enough space for two characters and a null-terminator
} Square;

// Structure to represent a chessboard
typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

// Other common types (like Move) can also be defined here

#endif // CHESS_TYPES_H

