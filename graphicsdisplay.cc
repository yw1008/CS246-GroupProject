#include "graphicsdisplay.h"

const int cellPixel = 12;

GraphicsDisplay::GraphicsDisplay()
    : xw{579, 579}, gridSize{96} {
    if (gridSize > 0) {
        cellSize = 579 / gridSize;
    }

    // fill 13x13 blocks with the same color
    size_t r =0;
    // for (size_t r = 0; r < gridSize; ++r) {
        for (size_t c = 0; c < gridSize; ++c) {
            // Determine which 12×12 block we're in
            size_t blockRow = r / 12;
            size_t blockCol = c / 12;

            // Alternate colors by block
            int color = ((blockRow + blockCol) % 2 == 0) ? Xwindow::Green : Xwindow::Blue;

            xw.fillRectangle(c * cellSize, r * cellSize, cellSize, cellSize, color);
        }
    // }
}


int GraphicsDisplay::getColorCode(const Colour c) {
    if (c == Colour::Black) {
        return Xwindow::Black;
    } else if (c == Colour::White) {
        return Xwindow::White;
    } 
    // else {
    //     throw std::invalid_argument("Unsupported color: need to be white or black");
    // }
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


// incorrect
// void GraphicsDisplay::notify(Subject &whoFrom) {
//     Info info = whoFrom.getInfo();
//     int row = info.pos.row;
//     int col = info.pos.col;

//     int pixelRow = row * cellPixel;
//     int pixelCol = col * cellPixel;

//     // Always redraw the background
//     int bgColor = (row + col) % 2 == 0 ? Xwindow::Green : Xwindow::Blue;
//     xw.fillRectangle(pixelCol, pixelRow, cellPixel, cellPixel, bgColor);

//     // If there's no piece to draw, stop here
//     if (info.piecetype == pieceType::Nothing) return;

//     Colour c = info.colour;

//     // Draw the piece based on type and color
//     if (info.piecetype == pieceType::Pawn) {
//         drawPawn(row, col, cellPixel, c);
//     } else if (info.piecetype == pieceType::King) {
//         drawKing(row, col, cellPixel, c);
//     } else if (info.piecetype == pieceType::Queen) {
//         drawQueen(row, col, cellPixel, c);
//     } else if (info.piecetype == pieceType::Rook) {
//         drawRook(row, col, cellPixel, c);
//     } else if (info.piecetype == pieceType::Knight) {
//         drawKnight(row, col, cellPixel, c);
//     } else if (info.piecetype == pieceType::Bishop) {
//         drawBishop(row, col, cellPixel, c);
//     }
// }
