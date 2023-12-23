#include "CUnit/Basic.h"
#include "chess_reader.h"

/* Test case functions: */
void test_isValidNotation_valid(void) {
    CU_ASSERT_TRUE(isValidNotation("e4"));
    CU_ASSERT_TRUE(isValidNotation("exd5"));
    CU_ASSERT_TRUE(isValidNotation("Nf3"));
    CU_ASSERT_TRUE(isValidNotation("Nxe5"));
    CU_ASSERT_TRUE(isValidNotation("O-O"));
    CU_ASSERT_TRUE(isValidNotation("O-O-O"));
}

void test_isValidNotation_invalid(void) {
    CU_ASSERT_FALSE(isValidNotation("Z5"));
    CU_ASSERT_FALSE(isValidNotation("a"));
    CU_ASSERT_FALSE(isValidNotation("e10"));
    CU_ASSERT_FALSE(isValidNotation("pawns"));
    CU_ASSERT_FALSE(isValidNotation("kingside"));
}

void test_parse_standard_notation_valid(void) {
    Move move;

    // Test for a valid move
    move = parse_standard_notation("e2e4");
    CU_ASSERT_EQUAL(move.startCol, 'e' - 'a');
    CU_ASSERT_EQUAL(move.startRow, '8' - '2');
    CU_ASSERT_EQUAL(move.endCol, 'e' - 'a');
    CU_ASSERT_EQUAL(move.endRow, '8' - '4');

    // Add more tests for different valid moves
}

void test_parse_standard_notation_invalid(void) {
    Move move;

    // Test for an invalid move
    move = parse_standard_notation("e9z3");
    CU_ASSERT_EQUAL(move.startRow, -1);
    CU_ASSERT_EQUAL(move.startCol, -1);
    CU_ASSERT_EQUAL(move.endRow, -1);
    CU_ASSERT_EQUAL(move.endCol, -1);

    // Add more tests for different invalid moves
}
