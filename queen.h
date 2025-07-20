#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include "board.h"
#include <string>

class Queen: public Piece {
    char name;
    const std::vector<moveType> possibleWays;
    
    public:
        Queen();

        char getName();

        bool isValid(const string &from, const string &to, const Board &b);
};

#endif
