#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "chess_game_state.h"

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define WHITE_PIECE_COLOR "\033[34m" // Blue color
#define BLACK_PIECE_COLOR "\033[31m" // Red color
#define BOARD_SIZE 8  // Assuming you have defined BOARD_SIZE

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

void set_square_notation(Square *square, int row, int col) {
    square->notation[0] = 'a' + col; // Column letter (lowercase)
    square->notation[1] = '1' + (BOARD_SIZE - 1 - row); // Row number
    square->notation[2] = '\0';    // Null-terminator
}

void display_board(const Chessboard *chessboard) {
    // Display column headers
    printf("   ");  // Add extra space for alignment
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", 'a' + col);  // Add space after each column letter
    }
    printf("\n");

    // Display each row
    for (int row = 0; row < BOARD_SIZE; row++) {
        // Display row number at the start with a space for alignment
        printf("%d ", BOARD_SIZE - row);

        // Display pieces with spaces
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf(" ");  // Print a space before each piece for alignment
            print_piece(chessboard->board[row][col].piece);
        }

        // Display row number at the end with a newline
        printf(" %d\n", BOARD_SIZE - row);
    }

    // Display column headers again
    printf("   ");  // Add extra space for alignment
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", 'a' + col);  // Add space after each column letter
    }
    printf("\n");
}



void initialize_board(Chessboard *chessboard) {
    // Loop through each square on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Set default empty square values
            chessboard->board[i][j].piece = '_';
            chessboard->board[i][j].is_occupied = false;
            
            // Set the notation for each square
            set_square_notation(&chessboard->board[i][j], i, j);

            // Set up pieces for the initial chess configuration
            if (i == 0 || i == 7) {  // Rooks, knights, bishops, queen, and king
                char pieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
                chessboard->board[i][j].piece = (i == 0) ? pieces[j] : toupper(pieces[j]);
                chessboard->board[i][j].is_occupied = true;
            } else if (i == 1 || i == 6) {  // Pawns
                chessboard->board[i][j].piece = (i == 1) ? 'p' : 'P';
                chessboard->board[i][j].is_occupied = true;
            }
        }
    }
}

void display_game(const char *pgn) {
    Chessboard chessboard;
    initialize_board(&chessboard);
    // display_board(&chessboard);
    // ... (rest of the function)
}

// Rest of your code
