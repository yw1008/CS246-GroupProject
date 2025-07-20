#include "computer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const std::string columns = "abcdefgh";
const std::string rows = "12345678";

// Helper to convert (row, col) to string position
std::string posStr(int row, int col) {
    return std::string(1, columns[col]) + rows[7 - row];
}

Computer::Computer(bool isWhite, int lvl) : Player(false, isWhite), level{lvl} {}

Computer::~Computer() {}

int Computer::getLevel() const {
    return level;
}

void Computer::move(Board &board) {
    std::srand(std::time(nullptr));

    for (int attempts = 0; attempts < 200; ++attempts) {
        int r1 = std::rand() % 8;
        int c1 = std::rand() % 8;
        int r2 = std::rand() % 8;
        int c2 = std::rand() % 8;

        std::string from = posStr(r1, c1);
        std::string to = posStr(r2, c2);

        char piece = board.getPiece(from);

        if (piece == ' ' || piece == '_') {
            continue;
        }
        if (isWhite() && !isupper(piece)) {
            continue;
        }
        if (!isWhite() && !islower(piece)) {
            continue;
        }

        char target = board.getPiece(to);

        // If moving to same square, skip
        if (from == to) {
            continue;
        }

        board.removePiece(to);
        board.addPiece(piece, to);
        board.removePiece(from);

        std::cout << "Computer moves: " << from << " " << to << std::endl;

        board.changeTurn();
        return;
    }

    std::cout << "Computer failed to find a legal move." << std::endl;
}
