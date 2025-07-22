#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "info.h"

using namespace std;

class Observer;

class Subject{
    vector<Observer*> observers;

    public:
        void notifyObservers();
        void attach(Observer *ob);
        virtual Info getInfo() const = 0;
};

#endif
