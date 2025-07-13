#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "piece.h"
#include "player.h"

class Board {
    std::vector<std::vector<Piece>> theBoard; // The actual board
    bool IsWhite;
    bool IsFinish;
    Player whiteP;
    Player blackP;
public:
    // construct empty board without pieces
    Board(); // default ctor

    // construct board with pieces in the default position
    // defBoard(); // ctor

    // allow to customize the initial position of pieces
    void setUp();

    // add char type of piece on the string position
    void addPiece(char piece, std::string pos);

    // remove piece on the string position
    void removePiece(std::string pos);

    // change the turn of player
    void changeTurn();

    // check current game flow
    bool isInCheckmate(bool iscm);
    bool isInCheck(bool isc);
    bool isInStalemate();

    // allow a single undo
    void undo();
};

// need ostream?
// std::ostream &operator<<(std::ostream &out, const Board &b);
#endif
