//
// Created by MacBook Pro on 6/20/20.
//

#include "GameEvent.h"

using namespace game;

EventListener::EventListener() {
    EventManager::add(this);
}

EventListener::~EventListener() {
    EventManager::remove(this);
}

int EventManager::id = 0;
std::set<EventListener *> EventManager::listeners = std::set<EventListener *>{};

void EventManager::add(EventListener *eventListener) {
    listeners.insert(eventListener);
}

void EventManager::remove(EventListener *eventListener) {
    listeners.erase(eventListener);
}

void EventManager::emit(const int &eventName, const Object &data) {
    for (auto listener : listeners) {
        listener->handleEvent(eventName, data);
    }

}

