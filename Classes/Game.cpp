//
// Created by long on 20/05/2020.
//

#include "Game.h"
#include "HelloWorldScene.h"
#include "Helper.h"

Game::Game(GameConfig gameConfig)
: gameConfig(gameConfig)
, gameNetwork(Helper::getSocketAddr(gameConfig.netWorkConfig.serverAddr, gameConfig.netWorkConfig.serverPort).c_str()) {
    auto scene = HelloWorld::createScene();
    cocos2d::Director::getInstance()->runWithScene(scene);

    gameNetwork.send("Hello from game");
}
