//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAME_H
#define WORM_GAME_H

#include "Configs/GameConfig.h"
#include "GameNetwork.h"
#include "Map/MapLogic.h"

class Game {
private:
    GameConfig gameConfig;
    GameNetwork gameNetwork;
    MapLogic mapLogic{{1024, 512}};
public:
    explicit Game(GameConfig gameConfig);
};

#endif //WORM_GAME_H
