#include "chess_game_state.h"

// Helper function to initialize the chessboard
void initialize_board(Chessboard *chessboard) {
    // Loop through each square on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Initialize as empty square
            chessboard->board[i][j].piece.type = EMPTY;
            chessboard->board[i][j].piece.color = NONE;
        }
    }

    // Set up pieces for the initial chess configuration
    // Rooks, knights, bishops, queen, and king
    PieceType initialRowPieces[BOARD_SIZE] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int j = 0; j < BOARD_SIZE; j++) {
        // Set pieces for white (row 0) and black (row 7)
        chessboard->board[0][j].piece = (ChessPiece){initialRowPieces[j], WHITE};
        chessboard->board[7][j].piece = (ChessPiece){initialRowPieces[j], BLACK};

        // Set pawns for white (row 1) and black (row 6)
        chessboard->board[1][j].piece = (ChessPiece){PAWN, WHITE};
        chessboard->board[6][j].piece = (ChessPiece){PAWN, BLACK};
    }
}

// Additional functions related to the game state can be added here

void initialize_game_state(GameState *gs) {
    // Initialize the player, status, and other elements of GameState
    gs->currentPlayer = WHITE; // Example initialization
    gs->status = ONGOING;
    initialize_board(&(gs->chessboard)); // Initialize the board as well
    // ... Any other initialization code ...
}

