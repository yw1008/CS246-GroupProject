#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "observer.h"
#include "window.h"
#include "info.h"
#include "subject.h"

class GraphicsDisplay : public Observer {
    Xwindow xw;
    size_t BOARD_SIZE = 8;
    size_t gridSize = 0;
    int cellSize = 0;

private:
    // draw each piece in board[r][c] position
    void drawPawn(size_t boardr, size_t boardc, int cellSize, const Colour &c);
    void drawKing(size_t boardr, size_t boardc, int cellSize, const Colour &c);
    void drawQueen(size_t boardr, size_t boardc, int cellSize, const Colour &c);
    void drawRook(size_t boardr, size_t boardc, int cellSize, const Colour &c);
    void drawKnight(size_t boardr, size_t boardc, int cellSize, const Colour &c);
    void drawBishop(size_t boardr, size_t boardc, int cellSize, const Colour &c);

public:
    GraphicsDisplay();
    int getColorCode(const Colour c);
    void notify(Subject &whoFrom) override;
    ~GraphicsDisplay() = default;
};

#endif
