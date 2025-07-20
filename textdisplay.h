#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theTD;
    const std::size_t boardSize = 8;
    
  public:
    TextDisplay();
    void notify(Subject &whoNotified) override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif
