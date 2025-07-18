#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include "board.h"
#include <string>

class Knight: public Piece {
    char name;

    public:
        Knight();

        bool isValid(const string &from, const string &to, const Board &b);

        char getName();
}; 

#endif
