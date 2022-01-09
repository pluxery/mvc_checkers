#pragma once

#include<set>


class Subject;

class Observer {
public:
    virtual void Update(Subject *subject) const = 0;
};

class Subject {
private:
    std::set<Observer *> _observers;

public:
    void Attach(Observer *observer) {
        _observers.emplace(observer);
    };

    void Notify() {
        for (auto observer: _observers) {
            observer->Update(this);
        }
    }

    virtual int getColor() const = 0;
};
