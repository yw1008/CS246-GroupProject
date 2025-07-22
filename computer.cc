#include "computer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

Computer::Computer(bool isWhite, int lvl) : Player{false, isWhite}, level{lvl} {}

Computer::~Computer() {}

int Computer::getLevel() const {
    return level;
}

void Computer::move(Board &board) {
    switch (level) {
        case 1:
            moveLevel1(board);
            break;
        case 2:
            moveLevel2(board);
            break;
        case 3:
            moveLevel3(board);
            break;
        default:
            moveLevel1(board);
            break;
    }
}

// Level 1
void Computer::moveLevel1(Board &board) {
    std::srand(std::time(nullptr));

    for (int attempts = 0; attempts < 500; ++attempts) {
        int r1 = std::rand() % 8;
        int c1 = std::rand() % 8;
        int r2 = std::rand() % 8;
        int c2 = std::rand() % 8;

        std::string from = std::string(1, 'a' + c1) + std::to_string(8 - r1);
        std::string to = std::string(1, 'a' + c2) + std::to_string(8 - r2);

        char piece = board.getPiece(from);
        if (piece == ' ' || piece == '_') {
            continue;
        }
        if (from == to) {
            continue;
        }

        board.removePiece(to);
        board.addPiece(piece, to);
        board.removePiece(from);
        board.changeTurn();

        std::cout << "Computer (Level 1) moves: " << from << " " << to << std::endl;
        return;
    }

    std::cout << "Computer (Level 1) failed to find a move." << std::endl;
}

// Level 2
void Computer::moveLevel2(Board &board) {
    std::srand(std::time(nullptr));

    for (int attempts = 0; attempts < 500; ++attempts) {
        int r1 = std::rand() % 8;
        int c1 = std::rand() % 8;
        int r2 = std::rand() % 8;
        int c2 = std::rand() % 8;

        std::string from = std::string(1, 'a' + c1) + std::to_string(8 - r1);
        std::string to = std::string(1, 'a' + c2) + std::to_string(8 - r2);

        char piece = board.getPiece(from);
        char target = board.getPiece(to);

        if (piece == ' ' || piece == '_') {
            continue;
        }
        if (from == to) {
            continue;
        }

        bool isCapture = (target != ' ' && target != '_');
        bool opponentPiece = (isWhite() && islower(target)) || (!isWhite() && isupper(target));

        if (isCapture && opponentPiece) {
            board.removePiece(to);
            board.addPiece(piece, to);
            board.removePiece(from);
            board.changeTurn();

            std::cout << "Computer (Level 2) captures: " << from << " " << to << std::endl;
            return;
        }
    }

    std::cout << "No captures or checks — falling back to Level 1...\n";
    moveLevel1(board);
}

// Level 3
void Computer::moveLevel3(Board &board) {
    std::srand(std::time(nullptr));

    for (int attempts = 0; attempts < 500; ++attempts) {
        int r1 = std::rand() % 8;
        int c1 = std::rand() % 8;
        int r2 = std::rand() % 8;
        int c2 = std::rand() % 8;

        std::string from = std::string(1, 'a' + c1) + std::to_string(8 - r1);
        std::string to = std::string(1, 'a' + c2) + std::to_string(8 - r2);

        char piece = board.getPiece(from);
        char target = board.getPiece(to);

        if (piece == ' ' || piece == '_') {
            continue;
        }
        if (from == to) {
            continue;
        }

        bool opponentPiece = (isWhite() && islower(target)) || (!isWhite() && isupper(target));
        bool isCapture = target != ' ' && target != '_';
        bool isSafe = true;

        if (isSafe && opponentPiece) {
            board.removePiece(to);
            board.addPiece(piece, to);
            board.removePiece(from);
            board.changeTurn();

            std::cout << "Computer (Level 3) safely captures: " << from << " " << to << std::endl;
            return;
        }
    }

    std::cout << "No safe captures — falling back to Level 2...\n";
    moveLevel2(board);
}
