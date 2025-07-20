#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include "board.h"
#include <string>

class Queen: public Piece {
    char name;

    public:
        Queen();

        char getName();

        bool isValid(const string &from, const string &to, const Board &b);
};

#endif
