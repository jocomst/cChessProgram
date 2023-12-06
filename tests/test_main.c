#include <CUnit/Basic.h>

// Declare test functions from both test files
void test_initialize_board(void);
void test_initialize_game_state(void);
void test_prompt_start_game(void);

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add the 'GameState' suite to the registry
    CU_pSuite pGameStateSuite = CU_add_suite("GameStateTestSuite", NULL, NULL);
    if (NULL == pGameStateSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the 'GameState' tests to the suite
    if ((NULL == CU_add_test(pGameStateSuite, "test of initialize_board()", test_initialize_board)) ||
        (NULL == CU_add_test(pGameStateSuite, "test of initialize_game_state()", test_initialize_game_state))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the 'GameController' suite to the registry
    CU_pSuite pGameControllerSuite = CU_add_suite("GameControllerTestSuite", NULL, NULL);
    if (NULL == pGameControllerSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the 'GameController' tests to the suite
    if (NULL == CU_add_test(pGameControllerSuite, "test of prompt_start_game()", test_prompt_start_game)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

