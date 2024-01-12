#ifndef CHESS_GAME_STATE_H
#define CHESS_GAME_STATE_H

#include <stdbool.h>
#define BOARD_SIZE 8


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

