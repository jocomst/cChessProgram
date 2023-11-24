#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include "chess_game_state.h"

// Function declarations
void display_board(const Chessboard *chessboard);
void display_game(const char *pgn);
void print_piece(char piece);  // New function for printing pieces with color
void set_square_notation(Square *square, int row, int col);

#endif // CHESS_DISPLAY_H
