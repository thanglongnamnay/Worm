//
// Created by MacBook Pro on 6/20/20.
//

#ifndef WORM_GAMEEVENT_H
#define WORM_GAMEEVENT_H

#include <string>
#include <any>
#include <unordered_map>
#include <set>

using Object = std::unordered_map<std::string, std::any>;

namespace game {

    class EventListener {
    public:
        EventListener();

        virtual ~EventListener();

        virtual void handleEvent(int eventName, const Object& data) {

        }
    };

    class EventManager {
    private:
        EventManager();

        static int id;

        static std::set<EventListener *> listeners;

    public:
        static void emit(const int &eventName, const Object& data);

        static void add(EventListener *eventListener);

        static void remove(EventListener *eventListener);

        static int nextId() {
            listeners = std::set<EventListener *>{};
            return ++id;
        }
    };

}

enum event {
    EVENT_EXPLODE,
    EVENT_RECEIVE_PACKET,
    EVENT_HIT,
    EVENT_DONE_CALCULATE,
    EVENT_PLAYER_DIE,
};

#endif //WORM_GAMEEVENT_H
