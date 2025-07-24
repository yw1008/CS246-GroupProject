#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "state.h"
#include "piece.h"
#include "player.h"
#include "textdisplay.h"
//#include "graphicdisplay.h"

class TextDisplay;
class GraphicDisplay;

struct History {
    Position startPos; // start position of the last move
    Position endPos; // end position of the last move
    pieceType removedPiece; // pieceType of the removed piece (if no piece is removed, Nothing)
    Colour removedColour; // piece colour of the removed piece
    bool isEmpty = true; // check if there is a last move (no first move is made / have done undo once)
};

class Board {
    std::vector<std::vector<Piece>> theBoard; // The actual board
    std::map<pieceType, int> whitePieceCount;
    std::map<pieceType, int> blackPieceCount;
    bool isWhite = true;
    bool isFinish;
    Position whiteK = {-1, -1}; // position of white King
    Position blackK = {-1, -1}; // position of black King
    History prev; // storing previous move and removed piece (if it exists)

    TextDisplay *td = nullptr;
    GraphicDisplay *gd = nullptr;
    
public:
    // construct empty board without pieces
    // Board(); // default ctor

    std::vector<std::vector<Piece>> getBoard();

    ~Board(); // dtor

    pieceType getPieceType(char piece);

    Colour getPieceColor(char piece);

    void addPieceCount(pieceType pt, Colour c);
    void removePieceCount(pieceType pt, Colour c);

    // convert string position into vector of size_t (row,col)
    std::vector<int> intPos(std::string pos);

    void setUp(string cmd, string type, string position, string c);

    // construct board with pieces in the default position
    void defBoard(); // ctor

    // allow to customize the initial position of pieces
    void init();

    // get the name of the type (distinguish piece type and color)
    char getPiece (std::string pos);

    // check if the move is valid
    bool isValidMove(std::string &startPos, std::string &endPos);

    // move piece from startpos to endpos
    void makeMove(std::string &startPos, std::string &endPos);

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

    std::vector<Position> getNextMove(std::string startPos);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

std::ostream &operator<<(std::ostream &out, const Board &b);
#endif
