#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "info.h"

using namespace std;

class Observer;

class Subject{
    vector<Observer*> observers;

    public:
        virtual bool getColour() const = 0; // White is true, black is false
        virtual Position getPosition() const = 0; // Get the position of the piece [row, column]
        void notifyObservers();
        void attach(Observer *ob);
};

#endif
