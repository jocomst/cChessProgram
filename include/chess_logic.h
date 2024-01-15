#ifndef CHESS_LOGIC_H
#define CHESS_LOGIC_H

#include "chess_types.h"


// Function declarations
void initialize_pieces(Chessboard *chessboard);
void move_piece(Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col);
int is_move_legal(const Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col);
// Function to check if a square is occupied based on GameState and Move
bool is_square_occupied(const GameState *gameState, const Move *move);
bool has_piece_moved(const GameState *gameState, const Move *move);
void apply_move(GameState *gameState, const Move *move);
bool pawn_move(GameState *gameState, const Move *move);

#endif // CHESS_LOGIC_H
