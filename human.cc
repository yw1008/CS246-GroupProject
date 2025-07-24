#include "human.h"
#include <iostream>
#include <string>
#include "game.h"
#include "board.h"

using namespace std;

Human::Human(bool isWhite, int lv) : Player(isWhite, lv) {}

//Human::~Human() = default;

void Human::move(unique_ptr<Board> b) {
    string startPos, endPos;
    if (!(cin >> startPos >> endPos)) {
        cerr << "Invalid input: must enter to positions" << endl;
    }
    // castling, pawn promotion
    
}
