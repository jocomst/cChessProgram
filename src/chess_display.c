#include <stdio.h>
#include <string.h>

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define WHITE_PIECE_COLOR "\033[37m" // White color
#define BLACK_PIECE_COLOR "\033[30m" // Black color

void print_piece(char piece) {
    if (piece >= 'A' && piece <= 'Z') {
        // White piece - print in white color
        printf(WHITE_PIECE_COLOR "%c" RESET_COLOR, piece);
    } else if (piece >= 'a' && piece <= 'z') {
        // Black piece - print in black color
        printf(BLACK_PIECE_COLOR "%c" RESET_COLOR, piece);
    } else {
        // Empty square or invalid character - print as is
        printf("%c", piece);
    }
}

#define BOARD_SIZE 8  // Assuming you have defined BOARD_SIZE

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

void initialize_board(Chessboard *chessboard) {
    char initial_board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    memcpy(chessboard->board, initial_board, sizeof(initial_board));
}

void display_game(const char *pgn) {
    Chessboard chessboard;
    initialize_board(&chessboard);

    // ... (rest of the function)
}

// Rest of your code
