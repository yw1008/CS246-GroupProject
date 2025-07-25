#include "piece.h"
#include "board.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Piece::Piece(int r, int c): 
    pT{pieceType::Nothing}, colour{Colour::Nothing}, pos{c, r}, mT{}, state{stateType::Nothing, Colour::Nothing}, 
    isFirstMove{true}, isEnPassant{false} {} 

bool Piece::isValid(const Position &to) {
    int diffr = to.row - pos.row, diffc = to.col - pos.col, div;
    if (diffr != 0) div = diffc/diffr;
    else if (diffc != 0) div = diffr/diffc;
    else div = 0;

    if (pT == pieceType::King || pT == pieceType::Queen) {
        if (diffr == 0 || diffc == 0 || div == 1 || div == -1) return true;
    } else if (pT == pieceType::Pawn) {
        if (colour == Colour::White) {
            return (((diffr = 1) && (diffc == 0 || diffc == -1 || diffc == 1)) || (diffr == 2 && diffc == 0));
        } else if (colour == Colour::Black) {
            return (((diffr = -1) && (diffc == 0 || diffc == -1 || diffc == 1)) || (diffr == -2 && diffc == 0));
        }
    } else if (pT == pieceType::Rook) {
        return (diffr == 0 || diffc == 0);
    }  else if (pT == pieceType::Bishop) {
        return (div == 1 || div == -1);
    } else if (pT == pieceType::Knight) {
        return (((diffr == 1 || diffr == -1) && (diffc == 2 || diffc == -2)) || ((diffr == 2 || diffr == -2) && (diffc == 1 || diffc == -1)));
    } else { // nothing
        cerr << "Cannot move empty piece." << endl;
        return false;
    }
 }

char Piece::getType() const {
    if(pT == pieceType::Bishop){
        if(colour == Colour::White){
            return 'B';
        } else {
            return 'b';
        }
    } else if(pT == pieceType::King){
        if(colour == Colour::White){
            return 'K';
        } else {
            return 'k';
        }
    } else if(pT == pieceType::Knight){
        if(colour == Colour::White){
            return 'N';
        } else {
            return 'n';
        }
    } else if(pT == pieceType::Pawn){
        if(colour == Colour::White){
            return 'P';
        } else {
            return 'p';
        }
    } else if(pT == pieceType::Queen){
        if(colour == Colour::White){
            return 'Q';
        } else {
            return 'q';
        }
    } else if(pT == pieceType::Rook){
        if(colour == Colour::White){
            return 'R';
        } else {
            return 'r';
        }
    } else {
        return ' ';
    }
}

void Piece::setMoveType(){
    if(pT == pieceType::Knight){
        mT = {moveType{1, 2, false}, moveType{1, -2, false}, moveType{-1, 2, false}, moveType{-1, -2, false}, moveType{2, 1, false}, moveType{-2, 1, false}, moveType{2, -1, false}, moveType{-2, -1, false}, moveType{1, 2, false}};
    } else if(pT == pieceType::Queen){
        mT = {moveType{1, 1, true}, moveType{0, 1, true}, moveType{1, 0, true}, moveType{-1, 0, true}, moveType{0, -1, true}, moveType{-1, -1, true}, moveType{1, -1, true}, moveType{-1, 1, true}};
    } else if(pT == pieceType::King){
        mT = {moveType{1, 1, false}, moveType{0, 1, false}, moveType{1, 0, false}, moveType{-1, 0, false}, moveType{0, -1, false}, moveType{-1, -1, false}, moveType{1, -1, false}, moveType{-1, 1, false}};
    } else if(pT == pieceType::Rook){
        mT = {moveType{1, 0, true}, moveType{0, 1, true}, moveType{-1, 0, true}, moveType{0, -1, true}};
    } else if(pT == pieceType::Bishop){
        mT = {moveType{1, 1, true}, moveType{1, -1, true}, moveType{-1, 1, true}, moveType{-1, -1, true}};
    } else if(pT == pieceType::Pawn){
        if(colour == Colour::White){
            // if(isFirstMove){
            // if(isEnPassant){
                mT = {moveType{0, 1, false}, moveType{1, 1, false}, moveType{-1, 1, false}, moveType{0, 2, false}};
            // } else{
            //     mT = {moveType{0, 1, false}, moveType{0, 2, false}};
            // }
            // } else{
            //     if(isEnPassant){
            //         mT = {moveType{0, 1, false}, moveType{1, 1, false}, moveType{-1, 1, false}};
            //     } else{
            //         mT = {moveType{0, 1, false}};
            //     }
            // }
        } else {
            // if(isFirstMove){
            // if(isEnPassant){
                mT = {moveType{0, -1, false}, moveType{-1, -1, false}, moveType{1, -1, false}, moveType{0, -2, false}};
            // } else{
            //     mT = {moveType{0, -1, false}, moveType{0, -2, false}};
            // }
            // } else{
            //     if(isEnPassant){
            //         mT = {moveType{0, -1, false}, moveType{-1, -1, false}, moveType{1, -1, false}};
            //     } else{
            //         mT = {moveType{0, -1, false}};
            //     }
            // }
        }
    }
}

Info Piece::getInfo() const {
    return Info{pT, colour, pos};
}

pieceType Piece::getPieceType(){
    return pT;
}

Colour Piece::getColour(){
    return colour;
}

void Piece::addPiece(pieceType p, Colour c){
    pT = p;
    colour = c;
    setMoveType();
    isFirstMove = false;
    notifyObservers();   
}

State Piece::getState(){
    return state;
}

vector<Position> Piece::nextMove(){ // to Board Class can get the vector of possible next move point who are not repeatable
    vector<Position> nextmove;
    for(size_t i = 0; i < mT.size(); ++i){
        Position next{pos.col + mT[i].colChange, pos.row + mT[i].rowChange};
        nextmove.emplace_back(next);
    }
    return nextmove;
}

vector<moveType> Piece::getMoveType(){
    return mT;
}

void Piece::setState(stateType sT, Colour c){
    state = {sT, c};
}

void Piece::removePiece(){
    pT = pieceType::Nothing;
    colour = Colour::Nothing;
    setMoveType();
    notifyObservers();
}
