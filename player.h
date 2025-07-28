#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <string>

class Board;

class Player {
    bool colour;
    int level; // 0 for the human otherwise, level of the computer
public:
    // Constructor
    Player(bool isWhite, int lv);

    virtual void move(std::string &startPos, std::string &endPos, Board* b) = 0;

    // Returns true if the player is white
    bool isWhite() const;

    int getLevel() const;
};

#endif
