// chess_pieces.h

typedef enum {
    WHITE,
    BLACK
} PawnColor;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    PawnColor color;
    Position position;
    bool hasMoved;
    bool isEnPassantEligible;
} Pawn;
