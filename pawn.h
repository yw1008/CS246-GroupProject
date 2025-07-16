#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "board.h"
#include <string>

class Pawn: public Piece {
    bool isFirstMove = 0;
    char name;
    char direction;

    public:
        Pawn();

        bool isValid(const string &from, const string &to, const Board &b);

        char getName();

        bool getIsFirstMove();

        bool isEnPassant(const string &from, const string &to, const board &b);

        char promotion();
};

#endif
