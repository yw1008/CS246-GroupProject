#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "board.h"
#include <string>

class Pawn: public Piece {
    bool isFirstMove;
    bool isEnPassant; //for the Pawn class
    const std::vector<moveType> possibleWays;

    public:
        // Pawn(bool fm, bool ep, std::vector<moveType> mt);
        Pawn(bool fm, bool ep, std::vector<moveType> pW);

        bool isValid(const string &to) override;

        char getName();

        std::vector<moveType> getMoveType();

        bool getIsFirstMove();

        bool EnPassant(const string &from, const string &to, const board &b);

        char promotion();
};

#endif
