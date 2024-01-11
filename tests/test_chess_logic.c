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

    apply_move(&testGameState, &testMove);

    // Assert that the move has been applied correctly
    // You may need to check the state of the start and end squares
    CU_ASSERT_TRUE(/* conditions to verify the move */);
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
    CU_ASSERT_TRUE(/* conditions to verify the one-square move */);

    // Reset GameState for the initial position
    // ...

    // Test for moving two squares forward on first move
    testMove.endRow = testMove.startRow + 2;
    testMove.endCol = testMove.startCol;
    apply_move(&testGameState, &testMove);
    CU_ASSERT_TRUE(/* conditions to verify the two-square move */);

    // Additional tests for obstruction or invalid moves
    // ...
}


// main() function is as you've described

