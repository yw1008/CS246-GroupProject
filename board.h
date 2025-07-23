#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "piece.h"
#include "player.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class TextDisplay;
class GraphicDisplay;

struct History {
    Position startPos; // start position of the last move
    Position endPos; // end position of the last move
    pieceType removedPiece; // pieceType of the removed piece (if no piece is removed, Nothing)
    Colour removedColour; // piece colour of the removed piece
    bool isEmpty = true; // check if there is a last move (no first move is made / have done undo once)
}

class Board {
    std::vector<std::vector<Piece>> theBoard; // The actual board
    bool isWhite;
    bool isFinish;
    Position whiteK; // position of white King
    Position blackK; // position of black King
    History prev; // storing previous move and removed piece (if it exists)

    TextDisplay *td = nullptr;
    GraphicDisplay *gd = nullptr;
    
public:
    // construct empty board without pieces
    // Board(); // default ctor

    ~Board(); // dtor

    pieceType getPieceType(char piece);

    Colour getPieceColor(char piece);

    // convert string position into vector of size_t (row,col)
    std::vector<int> intPos(const std::string& pos);

    void setUp();

    // construct board with pieces in the default position
    void defBoard(); // ctor

    // allow to customize the initial position of pieces
    void init();

    // get the name of the type (distinguish piece type and color)
    char getPiece (std::string pos);

    // move piece from startpos to endpos
    void makeMove(std::string startPos, std::string endPos);

    // change the turn of player
    void changeTurn();

    // check current game flow
    bool whiteKingCanMove();

    bool blackKingCanMove();

    std::string isInCheck();

    bool isStalemate();

    // allow a single undo
    void undo();

    std::vector<Position> allPossibleMoves();

    std::unique_ptr<std::vector<Position>> getNextMove(std::string startPos);
};

// need ostream?
std::ostream &operator<<(std::ostream &out, const Board &b);
#endif
