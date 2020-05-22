//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAME_H
#define WORM_GAME_H


#include "Configs/GameConfig.h"
#include "GameNetwork.h"

class Game {
private:
    GameConfig gameConfig;
    GameNetwork gameNetwork;
public:
    explicit Game(GameConfig gameConfig);
};


#endif //WORM_GAME_H
