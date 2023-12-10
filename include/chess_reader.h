#ifndef CHESS_READER_H
#define CHESS_READER_H

#include "chess_game_state.h"

#define MAX_MOVE_NOTATION_LEN 6  // Length to accommodate longer notations like "e8=Q+"

typedef struct {
    char notation[MAX_MOVE_NOTATION_LEN];
} Move;

// Function to read the player's move in algebraic notation
void read_player_move(char *input);

// Function to parse the player's move from algebraic notation into board coordinates
bool parse_algebraic_notation(const char *input, Move *move);

// Function to validate if a string is a valid algebraic chess notation
bool isValidNotation(const char *notation);

#endif // CHESS_READER_H
