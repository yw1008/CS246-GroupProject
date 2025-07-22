#include "piece.h"
#include "board.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
        if(colour = Colour::White){
            if(isFirstMove){
            if(isEnPassant){
                mT = {moveType{0, 1, false}, moveType{1, 1, false}, moveType{-1, 1, false}, moveType{0, 2, false}};
            } else{
                mT = {moveType{0, 1, false}, moveType{0, 2, false}};
            }
            } else{
                if(isEnPassant){
                    mT = {moveType{0, 1, false}, moveType{1, 1, false}, moveType{-1, 1, false}};
                } else{
                    mT = {moveType{0, 1, false}};
                }
            }
        } else {
            if(isFirstMove){
            if(isEnPassant){
                mT = {moveType{0, -1, false}, moveType{-1, -1, false}, moveType{1, -1, false}, moveType{0, -2, false}};
            } else{
                mT = {moveType{0, -1, false}, moveType{0, -2, false}};
            }
            } else{
                if(isEnPassant){
                    mT = {moveType{0, -1, false}, moveType{-1, -1, false}, moveType{1, -1, false}};
                } else{
                    mT = {moveType{0, -1, false}};
                }
            }
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

void Piece::changeState(bool adding, bool isWhite){ // when adding is running adding = true, if is White turn isWhite = true
    if(adding){
        if(isWhite){
            if(state.stateType == stateType::blackCheck){ // blackCheck is the piece where black piece can check
                state = State{stateType::bothCheck, state.hasMoved, state.colour};
            } else{
                state = State{stateType::whiteCheck, ps.hasMoved, ps.colour};
            }
        } else {
            if(state.stateType == stateType::whiteCheck){
                state = State{stateType::bothCheck, state.hasMoved, state.colour};
            } else {
                state = State{stateType::blackCheck, state.hasMoved, state.colour};
            }
        }
    } else {
        if(state.stateType == stateType::bothCheck){
            if(isWhite){
                state = State{stateType::blackCheck, state.hasMoved, state.colour};
            } else {
                state = State{stateType::whiteCheck, state.hasMoved, state.colour};
            }
        } else {
            state = State{stateType::Nothing, state.hasMoved, state.colour};
        }
    }
}

State Piece::getState(){
    return state;
}

vector<Position> Piece::nextMove(){ // to Board Class can get the vector of possible next move point who are not repeatable
    vector<Position> nextmove;
    for(int i = 0; i < mT.size(); ++i){
        Position next{pos.col + mT[i].colChange, pos.row + mT[i].rowChange};
        nextmove.emplace_back(next);
    }
    return nextmove;
}

vector<moveType> Piece::getMoveType(){
    return mT;
}

void Piece::removePiece(){
    pT = pieceType::Nothing;
    colour = Colour::Nothing;
}
