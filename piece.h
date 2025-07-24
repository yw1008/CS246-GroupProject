#ifndef PIECE_H
#define PIECE_H
#include "subject.h"
#include "state.h"
#include "info.h"
#include <vector>
#include <cstddef>

using namespace std;

struct moveType {
    int colChange, rowChange;
    bool repeatable;
};

class Piece : public Subject {
protected:
    pieceType pT;
    Colour colour;
    Position pos;
    State state;
    bool isFirstMove;
    bool isEnPassant;

public:
    Piece(int r, int c, pieceType type, Colour col);
    virtual ~Piece() = default;

    virtual std::vector<Position> nextMove() const = 0;
    virtual char getType() const = 0;

    Info getInfo() const override;
    Colour getColour() const;
    pieceType getPieceType() const;
    State getState() const;
    void setState(stateType sT, Colour c);

    Position getPosition() const;
    void setPosition(Position p);
    void setFirstMove(bool);
    void setEnPassant(bool);
};


/*
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
    
        // bool isValid(const Position &to); // Check the received move is in 

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
*/
#endif
