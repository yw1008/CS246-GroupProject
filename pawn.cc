#include "pawn.h"
#include <vector>
#include "info.h"

using namespace std;

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

Pawn::pawn(bool fm, bool ep, vector<moveType> mt): isFirstMove{fm}, isEnPassant{ep}, possibleWays{mt} {}  

bool Pawn::isValid(const string &to){
    Position pos = strToPos(to);
    if(isFirstMove){
        if(isEnPassant){
            vector<moveType> mt = [moveType{0, 1, true}, moveType{1, 1, ,false}, moveType{-1, 1, false}];
        } else{
            vector<moveType> mt = [moveType{0, 1, false}, moveType{0, 2, false}];
        }
    } else{
        vector<moveType> mt = [moveType{0, 1, false}];
    }

    for(size_t i = 0; i < mt.size(); i++){
        Position next{Piece::pos.c + mt[i].colChange, Piece::pos.r + mt[i].rowChange};
        if(next.col == to.col && next.row == to.row) return true;
    }

    return false;
}