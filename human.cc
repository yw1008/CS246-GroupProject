#include "human.h"
#include <iostream>
#include <string>
#include "Game.h"

Human::Human(bool isWhite) : Player(true, isWhite) {}

Human::~Human() {}

void Human::move(Game &game) {
    std::string from, to;
    std::cout << "Enter your move: ";
    std::cin >> from >> to;

    while (!game.makeMove(from, to)) {
        std::cout << "Invalid move. Try again: ";
        std::cin >> from >> to;
    }
}
