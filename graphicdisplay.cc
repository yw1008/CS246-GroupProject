#include "graphicsdisplay.h"

GraphicsDisplay::GraphicsDisplay(size_t n)
    : xw{579, 579}, gridSize{96} {
    if (gridSize > 0) {
        cellSize = 579 / gridSize;
    }

    // fill 12x12 blocks with the same color
    for (size_t r = 0; r < gridSize; ++r) {
        for (size_t c = 0; c < gridSize; ++c) {
            // Determine which 12x12 block we're in
            size_t blockRow = r / 12;
            size_t blockCol = c / 12;

            // Alternate colors by block
            int color = ((blockRow + blockCol) % 2 == 0) ? Xwindow::Green : Xwindow::Blue;

            xw.fillRectangle(c * cellSize, r * cellSize, cellSize, cellSize, color);
        }
    }
}