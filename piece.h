#ifndef PIECE_H
#define PIECE_H
#include "subject.h"
#include "observer.h"
#include "info.h"
#include <vector>

using namespace std;

struct moveType{
    int colChange, rowChange;
    bool repeatable; // true for sliders (B,R,Q), false for “leapers” (N,K,P)
};

class Piece: public Subject, public Observer {
    protected:
        pieceType pieceType;
        Colour colour;
        Position pos;
        //bool isAlive;
    public:
        virtual bool isValid(const &to) = 0; // Check the received move is in 

        Info getInfo();

        char getType() const;

        void addPiece(pieceType p, Colour c);

        void removePiece(pieceType p, Colour c)

        void notify() override;
};

#endif
