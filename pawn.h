#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include "board.h"
#include <string>

class Pawn : public Piece {
    bool isFirstMove;
    bool isEnPassant;
    std::vector<moveType> possibleWays;

public:
    Pawn(bool fm, bool ep, std::vector<moveType> pW);

    bool isValid(int fromRow, int fromCol, int toRow, int toCol, const std::vector<std::vector<Piece>> &board) override;

    char getName() override;

    std::vector<moveType> getMoveType() override;

    bool getIsFirstMove() const;

    bool EnPassant(int fromRow, int fromCol, int toRow, int toCol, const std::vector<std::vector<Piece>> &board) const;

    char promotion();
};

#endif

/*
class Pawn : public Piece {
public:
    Pawn(int r, int c, Colour col);

    std::vector<Position> nextMove() const override;
    char getType() const override;

    bool getIsFirstMove() const;
    void setFirstMove(bool val);
    void setEnPassant(bool val);
    bool canEnPassant(const Position &target) const;

    char promotionChoice() const; // To ask user which piece to promote to
};

#endif
*/

