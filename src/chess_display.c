#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>      // For STDOUT_FILENO
#include <sys/ioctl.h>   // For ioctl and TIOCGWINSZ

#include "chess_game_state.h"
#include "chess_logic.h"

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define WHITE_PIECE_COLOR "\033[34m" // Blue color
#define BLACK_PIECE_COLOR "\033[31m" // Red color
#define BOARD_SIZE 8  // Assuming you have defined BOARD_SIZE

// Function to get the current width of the terminal
int get_terminal_width() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void print_piece(ChessPiece piece) {
    char displayChar;
    switch (piece.type) {
        case PAWN:   displayChar = 'P'; break;
        case KNIGHT: displayChar = 'N'; break;
        case BISHOP: displayChar = 'B'; break;
        case ROOK:   displayChar = 'R'; break;
        case QUEEN:  displayChar = 'Q'; break;
        case KING:   displayChar = 'K'; break;
        case EMPTY:  displayChar = 'X'; break; // Representing empty squares with 'X'
        default:     displayChar = 'X'; break; // Default to 'X' if no valid piece type is found
    }

    if (piece.color == WHITE) {
        printf(WHITE_PIECE_COLOR "%c" RESET_COLOR, displayChar);
    } else if (piece.color == BLACK) {
        printf(BLACK_PIECE_COLOR "%c" RESET_COLOR, displayChar);
    } else {
        printf("%c", displayChar);
    }
}



void set_square_notation(Square *square, int row, int col) {
    square->notation[0] = 'a' + col; // Column letter (lowercase)
    square->notation[1] = '1' + (BOARD_SIZE - 1 - row); // Row number
    square->notation[2] = '\0';    // Null-terminator
}

void display_board(const GameState *gameState) {
    int terminalWidth = get_terminal_width();
    int boardWidth = (BOARD_SIZE * 2) + 1; // 2 characters per square plus 1 for the row labels
    int leftPadding = (terminalWidth - boardWidth) / 2; // Calculate left padding to center the board

    const Chessboard *chessboard = &(gameState->chessboard);

    // Display column headers
    printf("%*s", leftPadding + 2, ""); // Offset by 2 spaces for the row numbers
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", 'a' + col); // Add space after each column letter
    }
    printf("\n");

    // Display each row
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%*s", leftPadding, ""); // Align with left padding
        printf("%d ", BOARD_SIZE - row); // Display row number at the start with a space for alignment

        // Display pieces with spaces
        for (int col = 0; col < BOARD_SIZE; col++) {
            print_piece(chessboard->board[row][col].piece);
            printf(" "); // Print a space after each piece for alignment
        }

        // Display row number at the end with a newline
        printf("%d\n", BOARD_SIZE - row);
    }

    // Display column headers again
    printf("%*s", leftPadding + 2, ""); // Offset by 2 spaces for the row numbers
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", 'a' + col); // Add space after each column letter
    }
    printf("\n");
}



void display_game(const char *pgn) {
    GameState gameState;
    Chessboard chessboard;
    initialize_board(&chessboard);
    initialize_game_state(&gameState);
    // display_board(&chessboard);
    // ... (rest of the function)
}

void clear_screen() {
    // ANSI escape code to clear the screen and reset cursor position
    printf("\033[H\033[J");
}

void display_text(const char* text, int line_number) {
    // Move cursor to the beginning of the specified line
    printf("\033[%d;0H", line_number);

    // Clear the line using ANSI escape codes
    printf("\033[2K");

    // Output the new text
    printf("%s", text);
}

void display_intro_screen() {
    // Clear the screen
    printf("\033[H\033[J");

    // Print ASCII art here. Replace the following with your actual ASCII art.
    printf("    _____ _    _ ______  _____ _____ _      _____ \n");
    printf("  / ____| |  | |  ____|/ ____/ ____| |    |_   _|\n");
    printf(" | |    | |__| | |__  | (___| (___ | |      | |  \n");
    printf(" | |    |  __  |  __|  \\___ \\\\___ \\| |      | |  \n");
    printf(" | |____| |  | | |____ ____) |___) | |____ _| |_ \n");
    printf("  \\_____|_|  |_|______|_____/_____/|______|_____|\n");
    printf("                                                 \n");
    printf("                                                  \n");
}
