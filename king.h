#ifndef KING_H
#define KING_H
#include "piece.h"
#include <string>
#include "board.h"

class King: public Piece {
    char name;
    bool canMove; // true if King can move false otherwise

    public:
        King();

        bool isValid(const string &from, const string &to, const Board &b);

        char getName();

        bool isInCheck(const Board &b);
};

#endif
