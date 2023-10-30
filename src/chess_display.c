#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

void initialize_board(Chessboard *chessboard) {
    char initial_board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    memcpy(chessboard->board, initial_board, sizeof(initial_board));
}

void display_board(Chessboard *chessboard) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessboard->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void apply_move(Chessboard *chessboard, const char *move) {
    // TODO: Implement function to apply a chess move to the board.
    // This function will be more complex and will involve interpreting 
    // the move string and updating the board array accordingly.
}

void display_game(const char *pgn) {
    Chessboard chessboard;
    initialize_board(&chessboard);

    // Split the PGN by spaces to get individual moves or move numbers
    char *token = strtok(pgn, " ");

    while (token != NULL) {
        // Check if the token is a move number (ends with a period)
        int len = strlen(token);
        if (token[len - 1] == '.') {
            printf("%s ", token);
            token = strtok(NULL, " ");  // get the next token
            continue;  // skip to next iteration
        }

        printf("Move: %s\n", token);
        apply_move(&chessboard, token);
        display_board(&chessboard);

        token = strtok(NULL, " ");
    }
}


int main() {
    char sample_pgn[] = "1.e4 e5 2.Nf3 Nc6 3.Bc4 Bc5";  // Example PGN
    display_game(sample_pgn);
    return 0;
}

