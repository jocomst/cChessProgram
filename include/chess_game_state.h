#ifndef CHESS_GAME_STATE_H
#define CHESS_GAME_STATE_H

#include <stdbool.h>
#define BOARD_SIZE 8

// Enumerations for piece types and player colors
typedef enum {
    EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} PieceType;

typedef enum {
    BLACK, WHITE, NONE // NONE for empty squares
} PlayerColor;

// Structure for a chess piece
typedef struct {
    PieceType type;
    PlayerColor color;
    bool has_moved;
} ChessPiece;

// Modify your Square structure to include ChessPiece
typedef struct {
    ChessPiece piece;
    bool is_occupied;
    char notation[3];  // Retain your attribute for chess notation
} Square;

// Chessboard structure remains the same
typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

// Enum for game status
typedef enum {
    ONGOING, CHECKMATE, STALEMATE, DRAW
} GameStatus;

// Main game state structure
typedef struct {
    Chessboard chessboard;
    PlayerColor currentPlayer;
    GameStatus status;
} GameState;

void initialize_board(Chessboard *chessboard);

// Function to initialize the game state
void initialize_game_state(GameState *gs);

// Function declarations for initializing, updating game state...

#endif // CHESS_GAME_STATE_H

