#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>
#include "chess_reader.h"

// Helper function to simulate user input
void simulate_stdin(const char *input, char *buffer) {
    FILE *original_stdin = stdin;
    // Use fmemopen to create a stream from a memory buffer on systems that support it
    FILE *input_stream = fmemopen((void *)input, strlen(input), "r");

    // Temporarily replace stdin with the stream containing the simulated user input
    stdin = input_stream;

    // Call the function to test
    read_player_move(buffer);

    // Clean up and restore the original stdin
    stdin = original_stdin;
    fclose(input_stream);
}

// Test case for read_player_move
void test_read_player_move(void) {
    char buffer[100] = {0};  // Buffer to store the user input
    const char *test_input = "e2e4\n";  // Simulated user input including newline

    simulate_stdin(test_input, buffer);

    // Assert that the buffer contains the expected input, minus the newline
    CU_ASSERT_STRING_EQUAL(buffer, "e2e4");
}

int main() {
    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("ChessReaderTestSuite", NULL, NULL);

    // Add the test case to the suite
    CU_add_test(suite, "testReadPlayerMove", test_read_player_move);

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up and get the number of tests that failed
    unsigned int num_failures = CU_get_number_of_tests_failed();
    CU_cleanup_registry();

    // Return the number of test failures
    return num_failures;
}
