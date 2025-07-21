#include "knight.h"

Position strToPos(const string str){
    char col = str[0];
    char row = str[1];
    int c, r;

    c = col - 'a';
    stringstream ss;
    ss << row;
    ss >> r;
    --r;
    return Position{c, r};
}

Knight::Knight(): possibleWays{
    {1, 2, false},
    {1, -2, false},
    {-1, 2, false},
    {-1, -2, false}
} {}

bool Knight::isValid(const string &to){
    Position toPos = strToPos(to);

    for(std::size_t i = 0; i < possibleWays.size(), ++i){
        Position next{Piece::pos.col + possibleWays[i].colChange, Piece::pos.row + possibleWays[i].rowChange};
        if(next.col == toPos.col && next.row == toPos.row) return true;
    }

    return false;
}
