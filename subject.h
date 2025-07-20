#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

using namespace std;

class Observer;

class Subject{
    vector<Observer*> observers;

    public:
        virtual bool getColour() const = 0; // White is true, black is false
        virtual vector<std::size_t> getPosition() const = 0; // Get the position of the piece [row, column]
        void notifyObservers();
        void attach(Observer *ob);
};

#endif
