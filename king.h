#ifndef KING_H
#define KING_H
#include "piece.h"
#include <string>
#include "board.h"

class King: public Piece {
    char name;

    public:
        King();

        bool isValid(const string &from, const string &to, const Board &b);

        char getName();

        bool isInCheck(const Board &b);
};

#endif
