#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

// Function declarations
void initialize_board(Chessboard *chessboard);
void display_board(Chessboard *chessboard);
void display_game(const char *pgn);

#endif // CHESS_DISPLAY_H
