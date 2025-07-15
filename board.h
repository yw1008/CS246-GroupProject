#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "piece.h"
#include "player.h"

class Player;
class Piece;

class Board {
    std::vector<std::vector<Piece>> theBoard; // The actual board
    bool isWhite;
    bool isFinish;
    std::string prev; // storing previous command for a single undo

    TextDisplay *td = nullptr;

    Player *whiteP;
    Player *blackP;
public:
    // construct empty board without pieces
    Board(); // default ctor

    // convert string position into vector of integers
    std::vector intPos(std::string pos);

    // construct board with pieces in the default position
    void defBoard(); // ctor

    // allow to customize the initial position of pieces
    void init();

    // get the name of the type (distinguish piece type and color)
    void getPiece (std::string pos);

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
