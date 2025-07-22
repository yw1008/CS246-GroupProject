#ifndef PIECE_H
#define PIECE_H
#include "subject.h"
#include "observer.h"
#include "state.h"
#include "info.h"
#include <vector>
#include <cstddef>

using namespace std;

struct moveType{
    int colChange, rowChange;
    bool repeatable; // true for sliders (B,R,Q), false for “leapers” (N,K,P)
};

class Piece: public Subject, public Observer {
    protected:
        pieceType pT;
        Colour colour;
        Position pos;
        vector<moveType> mT;
        bool isFirstMove;
        bool isEnPassant; //for the Pawn class
        //bool isAlive;
    public:
        virtual bool isValid(const Position &to) = 0; // Check the received move is in 

        Info getInfo() const override;

        Colour getColour();

        pieceType getPieceType();

        void setMoveType();

        std::vector<Position> nextMove();

        char getType() const;

        void addPiece(pieceType p, Colour c); //set state and adding Check state on the possible next moves

        void removePiece();

        void notify(Subject &whoFrom, bool adding, bool isWhite) override;

        vector<moveType> Piece::getMoveType();
};

#endif
