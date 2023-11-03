typedef enum {
    PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} PieceType;

typedef enum {
    WHITE, BLACK
} PieceColor;

typedef struct {
    PieceType type;
    PieceColor color;
    bool hasMoved;
    // ... other attributes
} Piece;
