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
    
    // set the board for each game
    void setBoard(Board* b);
    // set the player for each game
    void setPlayers(Player* white, Player* black);

    // check if the move is valid
    bool isValidMove(std::string &startPos, std::string &endPos);

    // Makes a move from startPos to endPos
    void makeMove(std::string &startPos, std::string &endPos);

    // Returns true if the current player is in check
    std::string isInCheck() const;

    bool whiteKingCanMove() const;

    bool blackKingCanMove() const;

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
    void setIsFinished();

    // Returns true if the game is finished
    bool getIsFinished() const;
};

#endif
