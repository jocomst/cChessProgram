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

void test_parse_algebraic_notation(void) {
    Move move;
    CU_ASSERT_TRUE(parse_algebraic_notation("e4", &move));
    CU_ASSERT_STRING_EQUAL(move.notation, "e4");
    
    CU_ASSERT_FALSE(parse_algebraic_notation("e9", &move));
}
