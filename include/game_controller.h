// game_controller.h
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "chess_game_state.h"

// Function to prompt the user to start the game
void prompt_start_game(GameState *gameState);

void start_game_loop(GameState *gameState);

#endif // GAME_CONTROLLER_H

