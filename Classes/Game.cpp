//
// Created by long on 20/05/2020.
//

#include "Game.h"
Game* Game::instance = nullptr;
void Game::showLoginScene() {
	gameState = WAITING;
	currentScene = HelloWorld::create();
	cocos2d::Director::getInstance()->runWithScene(currentScene);

	currentScene->addChild(mapLogic.mapView);
	mapLogic.mapView->setVisible(false);
	guiLogin = GuiLogin::create();
	currentScene->addChild(guiLogin);
}
