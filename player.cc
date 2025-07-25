#include "player.h"

// Constructor
Player::Player(bool isWhite, int lv): colour{isWhite}, level{lv} {}

// Returns true if the player is human
// bool Player::isHuman() const {
//     return HumanOrComputer;
// }

// Returns true if the player is white
bool Player::isWhite() const {
    return colour;
}

int Player::getLevel() const {
    return level;
}

// Destructor
// Player::~Player() {}
