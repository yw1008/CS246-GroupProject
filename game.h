#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "player.h"
#include "board.h"
#include "piece.h"
#include <memory>

class Game {
    std::vector<int> score; // score[0] is white, score[1] is black
    bool isWhiteTurn;
    bool isFinished = true;

    unique_ptr<Player> whitePlayer;
    unique_ptr<Player> blackPlayer;
    unique_ptr<Board> board;

public:
    // Constructor
    Game();

    // Destructor
    //~Game();
    
    // set the board for each game
    void setBoard(unique_ptr<Board> b);
    // set the player for each game
    void setPlayers(unique_ptr<Player> white, unique_ptr<Player> black);

    // // Starts a new game with the given white and black players
    // void start(Player* white, Player* black, Board* b);

    // Makes a move from startPos to endPos
    void makeMove(const std::string &startPos, const std::string &endPos);

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
