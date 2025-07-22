#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "window.h"
#include "info.h"
#include "subject.h"

class GraphicsDisplay : public Observer {
    Xwindow xw;
    size_t BOARD_SIZE = 8;
    int cellSize = 0;

private:
    // draw each piece in board[r][c] position
    void drawPawn(size_t boardr, size_t boardc, int cellSize);
    void drawKing(size_t boardr, size_t boardc, int cellSize);
    void drawQueen(size_t boardr, size_t boardc, int cellSize);
    void drawRook(size_t boardr, size_t boardc, int cellSize);
    void drawKnight(size_t boardr, size_t boardc, int cellSize);
    void drawBishop(size_t boardr, size_t boardc, int cellSize);

public:
    GraphicsDisplay();
    int getColorCode(const std::string &color);
    void notify(Subject &whoFrom) override;
    ~GraphicsDisplay() = default;
};

#endif
