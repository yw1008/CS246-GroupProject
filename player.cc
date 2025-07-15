#include "Player.h"

// Constructor
Player::Player(bool isHuman, bool isWhite) : HumanOrComputer{isHuman}, colour{isWhite} {}

// Returns true if the player is human
bool Player::isHuman() const {
    return HumanOrComputer;
}

// Returns true if the player is white
bool Player::isWhite() const {
    return colour;
}

// Destructor
Player::~Player() {}
