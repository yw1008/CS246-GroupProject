#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "board.h"
#include <string>

class Pawn: public Piece {
    bool isFirstMove = true;
    bool isEnPassant = false; //for the Pawn class
    const std::vector<moveType> possibleWays;

    public:
        Pawn(bool fm, bool ep);

        bool isValid(const string &to) override;

        char getName();

        bool getIsFirstMove();

        bool isEnPassant(const string &from, const string &to, const board &b);

        char promotion();
};

#endif
