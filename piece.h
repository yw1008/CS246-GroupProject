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
        //bool isAlive;
    public:
        virtual bool isValid(const &to) = 0; // Check the received move is in 

        Info getInfo();

        pieceType getPieceType();

        char getType() const;

        void addPiece(pieceType p, Colour c);

        void removePiece();

        void notify() override;
};

#endif
