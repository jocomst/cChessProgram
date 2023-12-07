#include <CUnit/Basic.h>
#include "chess_game_state.h"
#include "test_cases.h"

void test_initialize_board(void) {
    Chessboard chessboard;
    initialize_board(&chessboard);

    // Test if the board is initialized with empty squares
    for (int i = 2; i < BOARD_SIZE - 2; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            CU_ASSERT(chessboard.board[i][j].piece.type == EMPTY);
            CU_ASSERT(chessboard.board[i][j].piece.color == NONE);
        }
    }

    // Test if the initial row is set up with the correct pieces for white and black
    PieceType initialRowPieces[BOARD_SIZE] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int j = 0; j < BOARD_SIZE; j++) {
        CU_ASSERT(chessboard.board[0][j].piece.type == initialRowPieces[j]);
        CU_ASSERT(chessboard.board[0][j].piece.color == WHITE);
        CU_ASSERT(chessboard.board[7][j].piece.type == initialRowPieces[j]);
        CU_ASSERT(chessboard.board[7][j].piece.color == BLACK);
        CU_ASSERT(chessboard.board[1][j].piece.type == PAWN);
        CU_ASSERT(chessboard.board[1][j].piece.color == WHITE);
        CU_ASSERT(chessboard.board[6][j].piece.type == PAWN);
        CU_ASSERT(chessboard.board[6][j].piece.color == BLACK);
    }
}

void test_initialize_game_state(void) {
    GameState gs;
    initialize_game_state(&gs);

    // Test if the game state is initialized correctly
    CU_ASSERT(gs.currentPlayer == WHITE);
    CU_ASSERT(gs.status == ONGOING);
    // Test if the board was initialized by the game state initialization
    CU_ASSERT(gs.chessboard.board[0][0].piece.type == ROOK);
    // ... Additional assertions can be added here ...
}

