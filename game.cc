#include "game.h"
#include "player.h"
#include "board.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructor
Game::Game() : score{0, 0}, isWhiteTurn{true}, isFinished{true}, whitePlayer{nullptr}, blackPlayer{nullptr}, board{nullptr} {}

// Destructor
// Game::~Game() {
//     delete whitePlayer;
//     delete blackPlayer;
//     delete board;
// }

void Game::setBoard(unique_ptr<Board> b) {
    board = move(b);
}

void Game::setPlayers(unique_ptr<Player> white, unique_ptr<Player> black) {
    whitePlayer = move(white);
    blackPlayer = move(black);
}
// // Start a new game with given players
// void Game::start(Player* white, Player* black, Board* b) {
//     whitePlayer = white;
//     blackPlayer = black;
//     board = b;
//     isWhiteTurn = true;
//     isFinished = false;
//     score[0] = 0;
//     score[1] = 0;
// }

// // Set up the board at the beginning of the game
// void Game::setUp() {
//     board.init();
//     // board gets the command for setUp
//     board->setUp();
// }

// Make a move from startPos to endPos
void Game::makeMove(const string &startPos, const string &endPos) {
    if (isFinished) {
        cout << "Game is already finished." << endl;
        return;
    }
    if (!board) {
        cout << "Board is not initialized." << endl;
        return;
    }

    // Move piece from startPos to endPos
    char type = board->getPiece(startPos);
    board->makeMove(startPos, endPos);
    // Change turn
    isWhiteTurn = !isWhiteTurn;
}

// Check if current player is in check
string Game::isInCheck() const {
    return board->isInCheck();
}

bool Game::whiteKingCanMove() const {
    if (!board) {
        return false;
    }
    return board->whiteKingCanMove();
}

bool Game::blackKingCanMove() const {
    if (!board) {
        return false;
    }
    return board->blackKingCanMove();
}

// Check if white player is in checkmate
bool Game::isWhiteInCheckmate() const {
    if (!board) {
        return false;
    }
    if(isInCheck() == "white"){
        if(!whiteKingCanMove()) return true;
        return false;
    } else if(isInCheck()  == "both"){
        if(!whiteKingCanMove()) return true;
        return false;
    } else {
        return false;
    }
}

// Check if black player is in checkmate
bool Game::isBlackInCheckmate() const {
    if (!board) {
        return false;
    }
    if(isInCheck() == "black"){
        if(!blackKingCanMove()) return true;
        return false;
    } else if(isInCheck()  == "both"){
        if(!blackKingCanMove()) return true;
        return false;
    } else {
        return false;
    }
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
void Game::setIsFinished() {
    if (isFinished) {
        isFinished = false;
    }
    isFinished = true;
}

// Returns true if game is finished
bool Game::getIsFinished() const {
    return isFinished;
}
