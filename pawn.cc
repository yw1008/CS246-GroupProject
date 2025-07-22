#include "pawn.h"
#include <vector>
#include "info.h"
#include <sstream>

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

// Pawn::Pawn(bool fm, bool ep, vector<moveType> mt): isFirstMove{fm}, isEnPassant{ep}, possibleWays{mt} {}  
Pawn::Pawn(bool fm, bool ep, vector<moveType> wP): isFirstMove{fm}, isEnPassant{ep}, possibleWays{wP} {}  

bool Pawn::isValid(const string &to){
    Position toPos = strToPos(to);
    vector<moveType> mt;
    if(isFirstMove){
        if(isEnPassant){
            mt = {moveType{0, 1, false}, moveType{1, 1, false}, moveType{-1, 1, false}, moveType{0, 2, false}};
        } else{
            mt = {moveType{0, 1, false}, moveType{0, 2, false}};
        }
    } else{
        if(isEnPassant){
            mt = {moveType{0, 1, false}, moveType{1, 1, false}, moveType{-1, 1, false}};
        } else{
            mt = {moveType{0, 1, false}};
        }
    }

    for(size_t i = 0; i < mt.size(); i++){
        Position next{Piece::pos.col + mt[i].colChange, Piece::pos.row + mt[i].rowChange};
        if(next.col == toPos.col && next.row == toPos.row) return true;
    }

    return false;
}

bool Pawn::getIsFirstMove(){
    return isFirstMove;
}

vector<moveType> Pawn::getMoveType(){
    return possibleWays;
}
