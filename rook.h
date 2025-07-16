#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include <string>
#include "board.h"

class Rook: public Piece {
    char name;

    public:
        Rook();

        bool isValid(const string &from, const string &to, const Board &b);

        char getName();
};

#endif
