#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "chess_game_state.h"

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define WHITE_PIECE_COLOR "\033[34m" // Blue color
#define BLACK_PIECE_COLOR "\033[31m" // Red color
#define BOARD_SIZE 8  // Assuming you have defined BOARD_SIZE

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
            // Initialize as empty square
            chessboard->board[i][j].piece.type = EMPTY;
            chessboard->board[i][j].piece.color = NONE;

            // Set the notation for each square
            set_square_notation(&chessboard->board[i][j], i, j);
        }
    }

    // Set up pieces for the initial chess configuration
    // Rooks, knights, bishops, queen, and king
    PieceType initialRowPieces[BOARD_SIZE] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int j = 0; j < BOARD_SIZE; j++) {
        // Set pieces for white (row 0) and black (row 7)
        chessboard->board[0][j].piece = (ChessPiece){initialRowPieces[j], WHITE};
        chessboard->board[7][j].piece = (ChessPiece){initialRowPieces[j], BLACK};

        // Set pawns for white (row 1) and black (row 6)
        chessboard->board[1][j].piece = (ChessPiece){PAWN, WHITE};
        chessboard->board[6][j].piece = (ChessPiece){PAWN, BLACK};
    }
}

void display_game(const char *pgn) {
    Chessboard chessboard;
    initialize_board(&chessboard);
    // display_board(&chessboard);
    // ... (rest of the function)
}

// Rest of your code
