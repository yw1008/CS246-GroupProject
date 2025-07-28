#include "graphicsdisplay.h"

const int cellPixel = 12;

GraphicsDisplay::GraphicsDisplay() {
    cellSize = 579 / BOARD_SIZE;

    // fill 8x8 blocks with the same color
    for (size_t r = 0; r < BOARD_SIZE; ++r) {
        for (size_t c = 0; c < BOARD_SIZE; ++c) {
            int color = ((r + c) % 2 == 0) ? Xwindow::Green : Xwindow::Blue;

            xw.fillRectangle(c * cellSize, r * cellSize, cellSize, cellSize, color);
        }
    }
    cellSize = 579 / 96;
}


int GraphicsDisplay::getColorCode(const Colour c) {
    if (c == Colour::Black) {
        return Xwindow::Black;
    } else if (c == Colour::White) {
        return Xwindow::White;
    } 
}

void GraphicsDisplay::drawPawn(size_t boardr, size_t boardc, int cellSize, const Colour &c) {
    int colourCode = getColorCode(c);

    xw.fillRectangle((3 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((4 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((5 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((6 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((7 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((8 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
}

void GraphicsDisplay::drawKing(size_t boardr, size_t boardc, int cellSize, const Colour &c) {
    int colourCode = getColorCode(c);

    xw.fillRectangle((3 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((4 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((5 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((6 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((7 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((8 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
}

void GraphicsDisplay::drawQueen(size_t boardr, size_t boardc, int cellSize, const Colour &c) {
    int colourCode = getColorCode(c);

    xw.fillRectangle((3 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((4 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((5 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((6 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((7 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((8 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
}

void GraphicsDisplay::drawRook(size_t boardr, size_t boardc, int cellSize, const Colour &c) {
    int colourCode = getColorCode(c);

    xw.fillRectangle((3 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((4 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((5 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((6 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((7 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((8 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
}

void GraphicsDisplay::drawKnight(size_t boardr, size_t boardc, int cellSize, const Colour &c) {
    int colourCode = getColorCode(c);

    xw.fillRectangle((4 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((5 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((6 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((7 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((8 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
}

void GraphicsDisplay::drawBishop(size_t boardr, size_t boardc, int cellSize, const Colour &c) {
    int colourCode = getColorCode(c);

    xw.fillRectangle((3 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((3 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((4 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((4 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((5 + boardc * 12) * cellSize, (1 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (2 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((5 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((6 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (6 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (7 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((6 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((7 + boardc * 12) * cellSize, (3 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (4 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (5 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (8 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((7 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);

    xw.fillRectangle((8 + boardc * 12) * cellSize, (9 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);
    xw.fillRectangle((8 + boardc * 12) * cellSize, (10 + boardr * 12) * cellSize, cellSize, cellSize, colourCode);  
}

void GraphicsDisplay::notify(Subject &whoFrom) {
    Info info = whoFrom.getInfo();
    int row = info.pos.row;
    int col = info.pos.col;

    int pixelRow = row * cellPixel;
    int pixelCol = col * cellPixel;

    cellSize = 579 / BOARD_SIZE;

    // If there's no piece to draw, stop here
    if (info.piecetype == pieceType::Nothing) {
        int color = ((row + col) % 2 == 0) ? Xwindow::Green : Xwindow::Blue;
        xw.fillRectangle(col * cellSize, row * cellSize, cellSize, cellSize, color);
    }

    Colour c = info.colour;
    cellSize = 579 / pixelSize;

    // Draw the piece based on type and color
    if (info.piecetype == pieceType::Pawn) {
        drawPawn(row, col, cellSize, c);
    } else if (info.piecetype == pieceType::King) {
        drawKing(row, col, cellSize, c);
    } else if (info.piecetype == pieceType::Queen) {
        drawQueen(row, col, cellSize, c);
    } else if (info.piecetype == pieceType::Rook) {
        drawRook(row, col, cellSize, c);
    } else if (info.piecetype == pieceType::Knight) {
        drawKnight(row, col, cellSize, c);
    } else if (info.piecetype == pieceType::Bishop) {
        drawBishop(row, col, cellSize, c);
    }
}
