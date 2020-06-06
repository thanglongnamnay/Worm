//
// Created by long on 20/05/2020.
//

#include "Game.h"
#include "Types/HP.h"
#include "HelloWorldScene.h"
#include "Helper.h"
#include "PhysicsShapeCache.h"

#include "Types/HP.h"
#include "Types/MP.h"

Game::Game(GameConfig gameConfig)
        :gameConfig(gameConfig),
         gameNetwork(Helper::getSocketAddr(gameConfig.serverAddr,
                 gameConfig.serverPort).c_str()) {
    auto scene = HelloWorld::create(gameNetwork);
    cocos2d::Director::getInstance()->runWithScene(scene);

    auto layer = LayerColor::create({40, 40, 40, 255});
    scene->addChild(layer);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    layer->addChild(mapLogic.mapView);
    mapLogic.mapView->refreshMap();
    gameNetwork.send(0, {0, 65, 66, 67});

//    auto map = Sprite::create("map_0.png");
//    map->setScale(.25);
//    map->setPosition(visibleSize / 2);
//    PhysicsShapeCache::getInstance()->addShapesWithFile("map_0.plist");
//    PhysicsShapeCache::getInstance()->setBodyOnSprite("map_0.plist", map);
//    layer->addChild(map);

//    auto sprite = Sprite::create("HelloWorld.png");
//    sprite->setPosition(visibleSize.width / 2, visibleSize.height);
//    sprite->setScale(.25);
//    layer->addChild(sprite);

//    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize() * .9,
//                                              PhysicsMaterial(0.1f, 1.0f, 0.0f));
//    physicsBody->setRotationEnable(false);
//    sprite->addComponent(physicsBody);
//
    layer->schedule([=](float dt) {
//        physicsBody->setVelocity(Vec2(cocos2d::random(-100,100),
//                                      cocos2d::random(-100,100)));
      CCLOG("FUCK");
    }, 1, "hello");
}
