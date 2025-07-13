#include "subject.h"
#include "observer.h"

//Register an observer with this subject
void Subject::attach(Observer *ob) {
    observers.emplace_back(ob);
}

// Notify all registered observers of a state change.
void Subject::notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}
