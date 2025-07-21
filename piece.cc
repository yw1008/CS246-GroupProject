#include "piece.h"
#include "board.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

char Piece::getType() {
    if(pieceType == pieceType::Bishop){
        if(colour == Colour::White){
            return 'B'
        } else {
            return 'b'
        }
    } else if(pieceType == pieceType::King){
        if(colour == Colour::White){
            return 'K'
        } else {
            return 'k'
        }
    } else if(pieceType == pieceType::Knight){
        if(colour == Colour::White){
            return 'N'
        } else {
            return 'n'
        }
    } else if(pieceType == pieceType::Pawn){
        if(colour == Colour::White){
            return 'P'
        } else {
            return 'p'
        }
    } else if(pieceType == pieceType::Queen){
        if(colour == Colour::White){
            return 'Q'
        } else {
            return 'q'
        }
    } else if(pieceType == pieceType::Rook){
        if(colour == Colour::White){
            return 'R'
        } else {
            return 'r'
        }
    }
}

Info Piece::getInfo() const {
    return Info{pieceType, colour, pos};
}

pieceType Piece::getPieceType(){
    return pT;
}

void Piece::addPiece(pieceType p, Colour c){
    pT = p;
    colour = c;
    if(pT == pieceType::Pawn){
        vector<moveType> Pawn::getMakeMove();
        for()
    } 
}

void Piece::removePiece(){
    pT = pieceType::Nothing;
    colour = Colour::Nothing;
}
