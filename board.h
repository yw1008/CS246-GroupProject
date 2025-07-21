#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "piece.h"
#include "player.h"

class Player;
class TextDisplay;
class GraphicDisplay;

class Board {
    std::vector<std::vector<Piece>> theBoard; // The actual board
    bool isWhite;
    bool isFinish;
    Board prev; // storing previous board data

    TextDisplay *td = nullptr;
    GraphicDisplay *gd = nullptr;

    Player *whiteP;
    Player *blackP;
public:
    // construct empty board without pieces
    Board(); // default ctor

    ~Board(); // dtor

    // convert string position into vector of size_t (row,col)
    std::vector intPos(std::string pos);

    // construct board with pieces in the default position
    void defBoard(); // ctor

    // allow to customize the initial position of pieces
    void init();

    // get the name of the type (distinguish piece type and color)
    char getPiece (std::string pos);

    // move piece from startpos to endpos
    void makeMove(std::string startPos, std::string endPos);

    // add char type of piece on the string position
    void addPiece(char piece, std::string pos);
    // remove piece on the string position
    void removePiece(std::string pos);

    // change the turn of player
    void changeTurn();

    // check current game flow
    bool isInCheckmate();
    bool isInCheck();
    bool isInStalemate();

    // allow a single undo
    void undo();
};

// need ostream?
std::ostream &operator<<(std::ostream &out, const Board &b);
#endif
