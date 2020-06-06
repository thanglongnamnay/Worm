//
// Created by long on 30/05/2020.
//

#ifndef WORM_OBSERVABLE_H
#define WORM_OBSERVABLE_H

#include <vector>
#include <list>
#include "Packet.h"

class Observable;

class IObserver {
private:
    Observable& subject;
public:
    ~IObserver();
    explicit IObserver(Observable& subject);
    virtual void onMessage(const Packet& packet) = 0;
};

class Observable {
private:
    std::list<IObserver*> observerList;
public:
    void attach(IObserver* observer) {
        observerList.push_back(observer);
    }
    void detach(IObserver* observer) {
        observerList.remove(observer);
    }

public:
    void notify(const Packet& packet) const {
        for (const auto& item : observerList) {
            item->onMessage(packet);
        }
    }
};
#endif //WORM_OBSERVABLE_H
