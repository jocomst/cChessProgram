#include <CUnit/Basic.h>
#include "chess_game_state.h"

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

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("GameStateTestSuite", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the tests to the suite
    if ((NULL == CU_add_test(pSuite, "test of initialize_board()", test_initialize_board)) ||
        (NULL == CU_add_test(pSuite, "test of initialize_game_state()", test_initialize_game_state))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

