// test_cases.h

#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "chess_game_state.h"
#include "game_controller.h"

// Declarations of test functions from test_chess_game_state.c
void test_initialize_board(void);
void test_initialize_game_state(void);

// Declarations of test functions from test_game_controller.c
void test_prompt_start_game(void);

// Add declarations for your new test functions in test_chess_logic.c
void test_is_square_occupied(void);
void test_has_piece_moved(void);
void test_apply_move(void);

#endif // TEST_CASES_H

