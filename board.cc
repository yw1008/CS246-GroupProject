#include "board.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

const int BOARD_SIZE = 8;

Board::Board(): 
        theBoard{BOARD_SIZE, std::vector<Piece>(BOARD_SIZE)}, 
        isWhite{true}, isFinish{false}, prev{""}, 
        whiteP{Player *wp}, balckP{Player *bp} {
    for (int r = 0; r < BOARD_SIZE; ++r) {
        for (int c = 0; c < BOARD_SIZE; ++c) {
            if (c%2 == 0) theBoard[r][c].type = '';
            else theBoard[r][c].type = '_';
        }
    }
} // not sure about the player for now

std::vector Board::intPos(std::string pos) {
    std::vector intPos;
    std::string col = pos[0];
    std::string row = pos[1];

    if (col == "a") intPos[0] = 0;
    else if (col == "b") intPos[0] = 1;
    else if (col == "c") intPos[0] = 2;
    else if (col == "d") intPos[0] = 3;
    else if (col == "e") intPos[0] = 4;
    else if (col == "f") intPos[0] = 5;
    else if (col == "g") intPos[0] = 6;
    else intPos[0] = 7;

    std::stringstream ss;
    ss << row;
    intPos[1] = ss - 1;

    return intPos;
}


void Board::defBoard() {
    // need to define other data within the Piece -> call piece ctor?

    // black
    //pawn
    for (int c = 0; c < BOARD_SIZE; ++c) {
        theBoard[1][c].type = 'p';
    }
    theBoard[0][0].type = 'r';
    theBoard[0][1].type = 'n';
    theBoard[0][2].type = 'b';
    theBoard[0][3].type = 'q';
    theBoard[0][4].type = 'k';
    theBoard[0][5].type = 'b';
    theBoard[0][6].type = 'n';
    theBoard[0][7].type = 'r';

    //white
    //pawn
    for (int c = 0; c < BOARD_SIZE; ++c) {
        theBoard[6][c].type = 'P';
    }
    theBoard[7][0].type = 'R';
    theBoard[7][1].type = 'N';
    theBoard[7][2].type = 'B';
    theBoard[7][3].type = 'Q';
    theBoard[7][4].type = 'K';
    theBoard[7][5].type = 'B';
    theBoard[7][6].type = 'N';
    theBoard[7][7].type = 'R';
}

void Board::init() {
    // clear existing board if necessary

    theBoard.clear();

}

void Board::addPiece(char piece, std::string pos) {
    std::vector intPos = intPos(pos);
    int r = intPos[1];
    int c= intPos[0];

    if (theBoard[r][c] != '' && theBoard[r][c] != '_') {
        //check if the move is invalid
        if (theBoard[r][c].isWhite && isWhite) {
            std::cerr << "Invalid move" << std::endl;
            return;
        }
        else if ((!theBoard[r][c].isWhite && !isWhite)) {
            std::cerr << "Invalid move" << std::endl;
            return;
        }

        //check if the move catch the other piece
        else removePiece(pos);
    }

    theBoard[r][c].type = piece;
}

void Board::removePiece(std::string pos) {
    std::vector intPos = intPos(pos);
    int r = intPos[1];
    int c= intPos[0];

    if (c%2 == 0) theBoard[r][c].type = '';
    else theBoard[r][c].type = '_';

    theBoard[r][c].isAlive = false;
}


void Board::changeTurn() {
    if (isWhite) isWhite = false;
    else isWhite = true;
}

bool Board::isInCheckmate();
bool Board::isInCheck();
bool Board::isInStalemate();

// allow a single undo
void Board::undo() {
    // check if there is previous move
    if (prev == "") std::cerr << "There is no previous action" << std::endl; 

}

