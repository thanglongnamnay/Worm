//
// Created by MacBook Pro on 6/24/20.
//

#ifndef WORM_PLAYER_H
#define WORM_PLAYER_H

#include <string>
#include <utility>
#include <Types/MP.h>
#include <Types/HP.h>
#include <Units/UnitPhysic.h>

class Player {
public:
    const int id;
    const std::string name;
    const std::shared_ptr<Worm> worm;
    HP hp;
    MP mp;

    Player(int id, std::string name) :
            id(id),
            name(std::move(name)),
            hp(100),
            mp(0),
            worm(std::make_shared<Worm>(rand() % 800, 400)) {}
};


#endif //WORM_PLAYER_H
