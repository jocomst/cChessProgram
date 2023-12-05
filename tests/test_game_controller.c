// Include CUnit test framework headers and the header for the component being tested
#include <CUnit/Basic.h>
#include <assert.h>
#include <unistd.h>
#include "game_controller.h"

// Your test functions and main function for CUnit...


// Define your test functions
void test_prompt_start_game(void) {
    GameState testGameState;

    // Redirect stdin to a buffer with the simulated input
    FILE *input_stream = fmemopen("s", 1, "r");
    stdin = input_stream;

    bool start = prompt_start_game(&testGameState);

    // Assert that the function returns true when 's' is the input
    assert(start == true);

    // Don't forget to restore the standard input and close the stream
    stdin = fdopen(STDIN_FILENO, "r");
    fclose(input_stream);
}

// Define your test suite
int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add suites to the registry
    CU_pSuite suite = CU_add_suite("GameControllerTestSuite", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if ((NULL == CU_add_test(suite, "test of prompt_start_game()", test_prompt_start_game))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

