#include "game.h"
#include "player.h"
#include "board.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructor
Game::Game() : score{0, 0}, isWhiteTurn{true}, isFinished{false}, whitePlayer{nullptr}, blackPlayer{nullptr}, board{nullptr} {}

// Destructor
Game::~Game() {
    delete whitePlayer;
    delete blackPlayer;
    delete board;
}

// Start a new game with given players
void Game::start(Player* white, Player* black) {
    whitePlayer = white;
    blackPlayer = black;
    board = new Board();
    setUp();
    isWhiteTurn = true;
    isFinished = false;
    score[0] = 0;
    score[1] = 0;
}

// Set up the board at the beginning of the game
void Game::setUp() {
    board.init();
    // board gets the command for setUp
    board->setUp();
}

// Make a move from startPos to endPos
void Game::makeMove(const string &startPos, const string &endPos) {
    if (isFinished) {
        cout << "Game is already finished.\n";
        return;
    }
    if (!board) {
        cout << "Board is not initialized.\n";
        return;
    }

    // Move piece from startPos to endPos
    char type = board->getPiece(startPos);
    board->makeMove(startPos, endPos);

    if (isInCheckmate()) {
        if (isWhiteTurn) {
            cout << "White wins by checkmate!\n";
        } else {
            cout << "Black wins by checkmate!\n";
        }
        isFinished = true;
    } else if (isInCheck()) {
        if (isWhiteTurn) {
            cout << "Black is in check.\n";
        } else {
            cout << "White is in check.\n";
        }
    } else if (board->isInStalemate()) {
        cout << "Game is a stalemate!\n";
        isFinished = true;
    }

    // Change turn
    isWhiteTurn = !isWhiteTurn;
}

// Check if current player is in check
bool Game::isInCheck() const {
    if (!board) {
        return false;
    }
    return board->isInCheck(isWhiteTurn);
}

// Check if current player is in checkmate
bool Game::isInCheckmate() const {
    if (!board) {
        return false;
    }
    return board->isInCheckmate(isWhiteTurn);
}

// Undo the last move
void Game::undo() {
    if (!board) {
        return;
    }
    board->undo();
    // Change turn
    isWhiteTurn = !isWhiteTurn;
    isFinished = false;
}

// Add a point to the score of the given color
void Game::addScore(const std::string &color) {
    if (color == "White") {
        ++score[0];
    } else if ("Black") {
        ++score[1];
    }
}

// Get the score for the given color
int Game::getScore(const std::string &color) const {
    if (color == "White") {
        return score[0];
    } else if (color == "Black") {
        return score[1];
    }
    return 0;
}

// Marks game as finished, specifying the winner
void Game::setIsFinished(const std::string &color) {
    if (isFinished) {
        return;
    }

    isFinished = true;
    std::cout << color << " wins!\n";
}

// Returns true if game is finished
bool Game::getIsFinished() const {
    return isFinished;
}
