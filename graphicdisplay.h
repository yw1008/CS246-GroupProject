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

public:
    GraphicsDisplay();
    void notify(Subject &whoFrom) override;
    ~GraphicsDisplay() = default;
};

#endif
