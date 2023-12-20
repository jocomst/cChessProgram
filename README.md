Chess Game in C
===============

Overview
--------

This project is a command-line based chess game implemented in C. It allows two players to engage in a chess match, applying standard chess rules and move validation. The game is designed to be interactive, user-friendly, and adheres to the conventional rules of chess.

Features
--------

-   Command-Line Interface: Engage in chess games via a straightforward and easy-to-navigate text interface.
-   Dynamic Move Validation: Validates player moves based on standard chess notation, considering each piece's unique movement capabilities.
-   Chessboard Display: The chessboard is dynamically displayed in the console, updating after each move to reflect the current game state.
-   Piece-Specific Movement Logic: Implements specific movement rules for each type of chess piece, including pawns, knights, bishops, rooks, queens, and kings.
-   Special Rules Implementation: Includes chess rules such as en passant, castling, and pawn promotion.
-   Game State Management: Manages and updates the game state after each move, checking for conditions such as check, checkmate, and stalemate.
-   Player Turn System: Alternates turns between players, ensuring the correct player makes a move at the right time.

Installation and Usage
----------------------

Clone the repository and compile the source code using a C compiler (like GCC). Run the compiled executable to start a game. The game will prompt you for moves in standard chess notation (e.g., `e2e4`, `g1f3`).

How to Play
-----------

After launching the game:

1.  The game will display an ASCII art intro screen and prompt you to start the game.
2.  Enter your moves using standard chess notation.
3.  The game will validate your moves, update the board, and switch turns between players.

Structure
---------

-   `main.c`: Entry point of the application. Handles the game loop.
-   `chess_display.c/h`: Functions for displaying the chessboard and game-related messages.
-   `chess_game_state.c/h`: Definitions and functions related to the game state, including the chessboard and player information.
-   `game_controller.c/h`: Core game logic, including game loop control and move processing.
-   `chess_reader.c/h`: Functions for reading and interpreting player input.
-   `chess_logic.c/h`: Implements logic for piece-specific movements and game rules.

Contributing
------------

Contributions to the project are welcome. Please ensure to follow the existing code structure and comment your code where necessary.
