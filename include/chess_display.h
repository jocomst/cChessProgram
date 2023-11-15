#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include "chess_game_state.h"

// Function declarations
void initialize_board(Chessboard *chessboard);
void display_board(const Chessboard *chessboard);
void display_game(const char *pgn);
void print_piece(char piece);  // New function for printing pieces with color

#endif // CHESS_DISPLAY_H
