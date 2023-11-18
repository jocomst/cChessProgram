#ifndef CHESS_READER_H
#define CHESS_READER_H

#include "chess_game_state.h"

// Function to read the player's move in algebraic notation
void read_player_move(char *input);

// Function to parse the player's move from algebraic notation into board coordinates
bool parse_algebraic_notation(const char *input, int *start_x, int *start_y, int *end_x, int *end_y);

#endif // CHESS_READER_H
