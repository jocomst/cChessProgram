#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "chess_game_state.h"

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


void display_board(const Chessboard *chessboard) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            print_piece(chessboard->board[i][j].piece); // Use print_piece to display each piece
            printf(" ");
        }
        printf("\n");
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
