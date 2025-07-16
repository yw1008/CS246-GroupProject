#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include "board.h"
#include <string>

class Bishop: public Piece {
    char name;

    public:
        Bishop();

        bool isValid(const string &from, const string &to, const Board &b);

        char getName();
};

#endif
