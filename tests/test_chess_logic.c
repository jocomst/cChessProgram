// Include CUnit test framework headers and the header for the component being tested
#include <CUnit/Basic.h>
#include <assert.h>
#include <unistd.h>
#include "chess_display.h"
#include "chess_reader.h"
#include "chess_logic.h"
#include "game_controller.h"  // Assuming this includes or indirectly includes all necessary type definitions

// Define your test functions
void test_is_square_occupied(void) {
    GameState testGameState;
    Move testMove;
    bool result;

    // Set up mock data for the test
    testMove.startRow = 0;
    testMove.startCol = 0;
    // Initialize GameState with appropriate data
    // ...

    result = is_square_occupied(&testGameState, &testMove);

    // Assert that the function works correctly for the given mock data
    CU_ASSERT_TRUE(result);
}

void test_has_piece_moved(void) {
    GameState testGameState;
    Move testMove;
    bool result;

    // Set up mock data for the test
    testMove.startRow = 0;
    testMove.startCol = 0;
    // Initialize GameState with appropriate data
    // ...

    result = has_piece_moved(&testGameState, &testMove);

    // Assert that the function correctly identifies if a piece has moved
    CU_ASSERT_TRUE(result);
}

void test_apply_move(void) {
    GameState testGameState;
    Move testMove;

    // Set up mock data for the test
    testMove.startRow = 0;
    testMove.startCol = 0;
    testMove.endRow = 1;
    testMove.endCol = 1;
    // Initialize GameState with appropriate data
    // ...
    
     // Temporary check to see if the starting square is occupied
    if (!is_square_occupied(&testGameState, &testMove)) {
        // The starting square is not occupied. Do not apply the move.
        printf("Cannot move from an empty square.\n");
        return;  // Exit the function early
    }

    apply_move(&testGameState, &testMove);

    // Assert that the move has been applied correctly
    // You may need to check the state of the start and end squares
    // The start square should now be empty and the end square should have a pawn
bool startSquareEmpty = (testGameState.chessboard.board[testMove.startRow][testMove.startCol].piece.type == EMPTY);
bool endSquareOccupied = (testGameState.chessboard.board[testMove.endRow][testMove.endCol].piece.type == PAWN &&
                          testGameState.chessboard.board[testMove.endRow][testMove.endCol].piece.color == 'W');

CU_ASSERT_TRUE(startSquareEmpty);
CU_ASSERT_TRUE(endSquareOccupied);
}

void test_pawn_move(void) {
    GameState testGameState;
    Move testMove;

    // Set up mock data for the initial position of the pawn
    // ...

    // Test for moving one square forward
    testMove.endRow = testMove.startRow + 1;
    testMove.endCol = testMove.startCol;
    apply_move(&testGameState, &testMove);

    // The start square should now be empty and the end square should have a pawn
bool startSquareEmpty = (testGameState.chessboard.board[testMove.startRow][testMove.startCol].piece.type == EMPTY);
bool endSquareOccupied = (testGameState.chessboard.board[testMove.endRow][testMove.endCol].piece.type == PAWN &&
                          testGameState.chessboard.board[testMove.endRow][testMove.endCol].piece.color == 'W');

CU_ASSERT_TRUE(startSquareEmpty);
CU_ASSERT_TRUE(endSquareOccupied);
}


// main() function is as you've described

