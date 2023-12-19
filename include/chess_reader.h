#ifndef CHESS_READER_H
#define CHESS_READER_H

#include "chess_game_state.h"

#define MAX_MOVE_NOTATION_LEN 6  // Length to accommodate longer notations like "e8=Q+"

typedef struct {
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    // Other fields as needed, such as promotion piece type
} Move;

// Function to read the player's move in algebraic notation
void read_player_move(char *input, const GameState *gameState);

// Function to parse the player's move from standard notation into move struct
Move parse_standard_notation(const char *input);

// Function to validate if a string is a valid algebraic chess notation
bool isValidNotation(const char *notation);

#endif // CHESS_READER_H
