#include "textdisplay.h"
#include <iostream>

using namespace std;

const std::size_t BOARD_SIZE = 8;

TextDisplay::TextDisplay()
    : theTD(BOARD_SIZE, vector<char>(BOARD_SIZE)) {
    for (size_t r = 0; r < BOARD_SIZE; ++r) {
        for (size_t c = 0; c < BOARD_SIZE; ++c) {
            theTD[r][c] = (r % 2 == c % 2) ? '_' : ' ';
        }
    }
}

void TextDisplay::notify(Subject &whoNotified) {
    Info info = whoNotified.getInfo();
    Colour c = info.colour;
    pieceType type = info.piecetype;
    if (type == pieceType::Nothing) {
        theTD[info.pos.row][info.pos.col] = (info.pos.row % 2 == info.pos.col % 2) ? '_' : ' ';
    }
    if (c == Colour::White) {
        if (type == pieceType::King) theTD[info.pos.row][info.pos.col] = 'K';
        else if (type == pieceType::Queen) theTD[info.pos.row][info.pos.col] = 'Q';
        else if (type == pieceType::Rook) theTD[info.pos.row][info.pos.col] = 'R';
        else if (type == pieceType::Knight) theTD[info.pos.row][info.pos.col] = 'N';
        else if (type == pieceType::Bishop) theTD[info.pos.row][info.pos.col] = 'B';
        else if (type == pieceType::Pawn) theTD[info.pos.row][info.pos.col] = 'P';
    }
    else {
        if (type == pieceType::King) theTD[info.pos.row][info.pos.col] = 'k';
        else if (type == pieceType::Queen) theTD[info.pos.row][info.pos.col] = 'q';
        else if (type == pieceType::Rook) theTD[info.pos.row][info.pos.col] = 'r';
        else if (type == pieceType::Knight) theTD[info.pos.row][info.pos.col] = 'n';
        else if (type == pieceType::Bishop) theTD[info.pos.row][info.pos.col] = 'b';
        else if (type == pieceType::Pawn) theTD[info.pos.row][info.pos.col] = 'p';
    }
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    size_t colNum = BOARD_SIZE;
    for (size_t r = 0; r < BOARD_SIZE; ++r) {
        out << colNum << " ";
        --colNum;
        for (size_t c = 0; c < BOARD_SIZE; ++c) {
            out << td.theTD[r][c];
        }
        out << endl;
    }
    out << endl;
    out << " abcdefgh" << endl;
    return out;
}
