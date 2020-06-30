//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAME_H
#define WORM_GAME_H

#include "Configs/GameConfig.h"
#include "GameNetwork.h"
#include "Map/MapLogic.h"
#include "HelloWorldScene.h"
#include "Helper.h"

#include "Types/HP.h"
#include "Types/MP.h"

enum GameState {
    WAITING,
    PLAYING,
};

class Game {
private:
    GameConfig gameConfig;
    GameNetwork gameNetwork;
    MapLogic mapLogic{{1024, 512}};
    GameState gameState = WAITING;
    std::vector<Player> players;
    std::vector<Player>::iterator currentPlayer;
public:
    static Game* instance;
    explicit Game(GameConfig gameConfig)
            : gameConfig(gameConfig),
              gameNetwork(Helper::getSocketAddr(gameConfig.serverAddr,
                                                gameConfig.serverPort).c_str()) {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Worm/texture.plist", "Worm/texture.png");
        prepareGame();
        startGame(0);
    }

    void login(const std::string& name) {
        gameNetwork.send(CMD::LOGIN, {name});
    }

    void addPlayer(const Player &player) {
        mapLogic.addUnit(player.worm);
        players.push_back(player);
    }

    void removePlayer(int id) {
        auto player = std::find_if(players.begin(), players.end(),
                                   [=](const Player &player) { return player.id == id; });
    }

    void removeAllPlayer() {
        players.clear();
    }

    void nextTurn(int id) {
        currentPlayer = std::find_if(players.begin(), players.end(),
                                     [=](const Player &player) { return player.id == id; });
    }

    void nextTurn() {
        ++currentPlayer;
        if (currentPlayer == players.end()) currentPlayer = players.begin();
    }

    void prepareGame() {
        gameState = WAITING;
        auto scene = HelloWorld::create();
        cocos2d::Director::getInstance()->runWithScene(scene);

        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        scene->addChild(mapLogic.mapView);
        mapLogic.mapView->refreshMap();
    }

    void startGame(int id) {
        gameState = PLAYING;

        mapLogic.mapView->refreshMap();
        gameNetwork.send(0, {0, 65, 66, 67});

        for (int i = 0; i < 4; ++i) {
            addPlayer({0, "p" + to_string(i)});
        }
        mapLogic.mapView->schedule([=](float dt) {
            mapLogic.update(dt);
        }, 0.0f, "update");

        const auto listener = cocos2d::EventListenerKeyboard::create();
        listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event *event) {
            CCLOG("Key pressed");
            if (gameState != PLAYING) return;
            auto worm = currentPlayer->worm;
            if (worm->isStable) {
                switch (keyCode) {
                    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                    case EventKeyboard::KeyCode::KEY_A:
                        worm->vy = 20;
                        worm->vx = -10;
                        break;
                    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                    case EventKeyboard::KeyCode::KEY_D:
                        worm->vy = 20;
                        worm->vx = 10;
                        break;
                    case EventKeyboard::KeyCode::KEY_UP_ARROW:
                    case EventKeyboard::KeyCode::KEY_W:
                        worm->angle += 10;
                        worm->refreshIndicate();
                        break;
                    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                    case EventKeyboard::KeyCode::KEY_S:
                        worm->angle -= 10;
                        worm->refreshIndicate();
                        break;
                    case EventKeyboard::KeyCode::KEY_SPACE:
                        mapLogic.addUnit(worm->makeBullet());
                        nextTurn();
                        break;
                    default:
                        break;
                }
            }
        };
        listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event *event) {
            if (gameState != PLAYING) return;
            auto worm = currentPlayer->worm;
            worm->ay = 0;
            worm->ax = 0;
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,
                                                                                              mapLogic.mapView);
        nextTurn(id);
    }

    void restartGame(int id) {
        removeAllPlayer();
        startGame(id);
    }
};

#endif //WORM_GAME_H
