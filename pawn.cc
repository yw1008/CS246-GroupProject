#include "pawn.h"
#include <vector>
#include "info.h"
#include <sstream>

using namespace std;

Pawn::Pawn(bool fm, bool ep, vector<moveType> wP) : isFirstMove{fm}, isEnPassant{ep}, possibleWays{wP} {}

// Main move validity check for pawn
bool Pawn::isValid(int fromRow, int fromCol, int toRow, int toCol,
                   const vector<vector<Piece>> &board) {
    Colour col = getColour();
    int direction = 1;
    if (col == Colour::White) {
        direction = -1;
    }

    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    const Piece &target = board[toRow][toCol];

    if (colDiff == 0) {
        // One step forward
        if (rowDiff == direction && target.getPieceType() == pieceType::Nothing) {
            return true;
        }

        // Two steps forward on first move
        if (rowDiff == 2 * direction && isFirstMove) {
            int midRow = fromRow + direction;
            if (board[midRow][fromCol].getPieceType() == pieceType::Nothing &&
                target.getPieceType() == pieceType::Nothing) {
                return true;
            }
        }

        // Forward move blocked
        return false;
    }

    if (abs(colDiff) == 1 && rowDiff == direction) {
        if (target.getPieceType() != pieceType::Nothing &&
            target.getColour() != col) {
            return true;
        }

        if (EnPassant(fromRow, fromCol, toRow, toCol, board)) {
            return true;
        }

        return false;
    }

    return false;
}

// Getter for name
char Pawn::getName() {
    return (getColour() == Colour::White) ? 'P' : 'p';
}

// Move patterns (for debugging or general use)
vector<moveType> Pawn::getMoveType() {
    return possibleWays;
}

// Getter for first move status
bool Pawn::getIsFirstMove() {
    return isFirstMove;
}

// Placeholder en passant checker
bool Pawn::EnPassant(int fromRow, int fromCol, int toRow, int toCol,
                     const vector<vector<Piece>> &board) const {
    // Real en passant requires move history; this just prevents crashes for now
    return false;
}

// Promotion choice (stub)
char Pawn::promotion() {
    return 'Q';
}


/*
Pawn::Pawn(int r, int c, Colour col)
    : Piece(r, c, pieceType::Pawn, col) {}

std::vector<Position> Pawn::nextMove() const {
    std::vector<Position> moves;
    int direction = (colour == Colour::White) ? 1 : -1;

    // Standard move forward
    Position oneStep{pos.col, pos.row + direction};
    moves.push_back(oneStep);

    // First move double step
    if (isFirstMove) {
        Position twoStep{pos.col, pos.row + 2 * direction};
        moves.push_back(twoStep);
    }

    // Diagonal captures
    moves.push_back({pos.col + 1, pos.row + direction});
    moves.push_back({pos.col - 1, pos.row + direction});

    return moves;
}

char Pawn::getType() const {
    return (colour == Colour::White) ? 'P' : 'p';
}

// Helper methods
bool Pawn::getIsFirstMove() const {
    return isFirstMove;
}

void Pawn::setFirstMove(bool val) {
    isFirstMove = val;
}

void Pawn::setEnPassant(bool val) {
    isEnPassant = val;
}

bool Pawn::canEnPassant(const Position &target) const {
    return isEnPassant && (
        (target.col == pos.col + 1 || target.col == pos.col - 1) &&
        (target.row == pos.row + ((colour == Colour::White) ? 1 : -1))
    );
}

char Pawn::promotionChoice() const {
    // Temporary placeholder
    return 'Q';
}
*/
