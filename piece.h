#ifndef PIECE_H
#define PIECE_H
#include "subject.h"
#include "state.h"
#include "info.h"
#include <vector>
#include <cstddef>

using namespace std;

struct moveType{
    int colChange, rowChange;
    bool repeatable; // true for sliders (B,R,Q), false for “leapers” (N,K,P)
};

class Piece: public Subject {
    protected:
        pieceType pT;
        Colour colour;
        Position pos;
        vector<moveType> mT;
        State state;
        bool isFirstMove;
        bool isEnPassant; //for the Pawn class
        //bool isAlive;
    public:
        Piece(int r, int c);

        bool isValid(const Position &to); // Check the received move is in 

        Info getInfo() const override;

        Colour getColour();

        pieceType getPieceType();

        void setMoveType();

        State getState();

        void setState(stateType sT, Colour c);

        std::vector<Position> nextMove();

        char getType() const;

        void addPiece(pieceType p, Colour c); //set state and adding Check state on the possible next moves

        void removePiece();

        vector<moveType> getMoveType();
};

#endif
