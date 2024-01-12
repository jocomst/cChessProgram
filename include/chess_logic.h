#ifndef CHESS_LOGIC_H
#define CHESS_LOGIC_H


// Enum to represent the types of chess pieces
typedef enum {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    EMPTY   // To represent an empty square
} PieceType;

// Structure to represent a chess piece
typedef struct {
    PieceType type;
    char color; // 'W' for white, 'B' for black
    bool has_moved; 
} ChessPiece;

typedef struct {
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    // Other fields as needed, such as promotion piece type
} Move;

typedef enum {
    BLACK, WHITE, NONE // NONE for empty squares
} PlayerColor;

// Structure for a chess piece
typedef struct {
    PieceType type;
    PlayerColor color;
    bool has_moved;
} ChessPiece;

// Modify your Square structure to include ChessPiece
typedef struct {
    ChessPiece piece;
    bool is_occupied;
    char notation[3];  // Retain your attribute for chess notation
} Square;

// Chessboard structure remains the same
typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;


// Function declarations
void initialize_pieces(Chessboard *chessboard);
void move_piece(Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col);
int is_move_legal(const Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col);
// Function to check if a square is occupied based on GameState and Move
bool is_square_occupied(const GameState *gameState, const Move *move);
bool has_piece_moved(const GameState *gameState, const Move *move);
void apply_move(GameState *gameState, const Move *move);

#endif // CHESS_LOGIC_H
