#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include "chess_game_state.h"
#include "chess_types.h"

// Function declarations
void display_board(const GameState *gameState);
void display_game(const char *pgn);
void print_piece(char piece);  // New function for printing pieces with color
void set_square_notation(Square *square, int row, int col);
void display_text(const char* text, int line_number);
void display_intro_screen();
void clear_screen();
int get_terminal_width();

#endif // CHESS_DISPLAY_H
