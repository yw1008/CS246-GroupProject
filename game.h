#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "player.h"
#include "board.h"
#include "piece.h"

class Game {
    std::vector<int> score; // score[0] is white, score[1] is black
    bool isWhiteTurn;
    bool isFinished;

    Player* whitePlayer;
    Player* blackPlayer;
    Board* board;

public:
    // Constructor
    Game();

    // Destructor
    ~Game();

    // Starts a new game with the given white and black players
    void start(Player* white, Player* black);

    // Sets up the game board and pieces before starting
    void setUp();

    // Makes a move from startPos to endPos
    void makeMove(const std::string &startPos, const std::string &endPos);

    // Returns true if the current player is in check
    std::string isInCheck() const;

    bool Game::whiteKingCanMove();

    bool Game::blackKingCanMove();

    // Returns true if the current player is in checkmate
    bool isWhiteInCheckmate() const;
    
    bool isBlackInCheckmate() const;

    // Undoes the last move made
    void undo();

    // Adds a point to the specified player's score
    void addScore(const std::string &color);

    // Returns the current score of the specified player
    int getScore(const std::string &color) const;

    // Marks the game as finished specifying which color won
    void setIsFinished(const std::string &color);

    // Returns true if the game is finished
    bool getIsFinished() const;
};

#endif
