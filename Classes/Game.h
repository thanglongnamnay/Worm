//
// Created by long on 20/05/2020.
//

#ifndef WORM_GAME_H
#define WORM_GAME_H

#include <Guis/GuiLogin.h>
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

class Game : game::EventListener {
private:
	GameConfig gameConfig;
	GameNetwork gameNetwork;
	MapLogic mapLogic{{1024, 512}};
	GameState gameState = WAITING;
	std::vector<Player> players;
	std::vector<Player>::iterator currentPlayer;
	std::vector<Player>::iterator myPlayer;

	Scene* currentScene = nullptr;
	Node* guiLogin = nullptr;
	void handleEvent(int eventName, const Object& data) override {
		EventListener::handleEvent(eventName, data);
		if (eventName == event::EVENT_RECEIVE_PACKET) {
			auto cmd = any_cast<int>(data.at("cmd"));
			auto params = any_cast<Params>(data.at("params"));
			handleNetworkCmd(static_cast<CMD>(cmd), params);
			return;
		}
	}
	void handleNetworkCmd(CMD cmd, Params& params) {
		CCLOG("handleNetworkCmd: %d", (int)cmd);
		switch (cmd) {
		case LOGIN: prepareGame();
			break;
		case JOIN_ROOM: {
			const auto seed = params.getInt();
			const auto id = params.getInt();
			const auto name = params.getString();
			const auto x = params.getInt();
			const auto y = params.getInt();
			const auto hp = params.getInt();
			const auto mp = params.getInt();

			mapLogic.recreateMap(seed);
			CCLOG("JOIN_ROOM: %d, %s, %d, %d, %d, %d", id, name.c_str(), x, y, hp, mp);
			addPlayer({id, name, x, y, hp, mp});
			break;
		}
		case START: {
			const auto id = params.getInt();
			CCLOG("START: %d", id);
			startGame(id);
			break;
		}
		case YOUR_ID: {
			const auto id = params.getInt();
			CCLOG("YOUR_ID: %d", id);
			myPlayer = find_if(players.begin(), players.end(), [=](const Player& p) { return p.id == id; });
			break;
		}
		default:
			CCLOG("Unhandled case: %d", cmd);
			break;
			// TODO: implement this shit
		}
	}
public:
	static Game* instance;
	explicit Game(GameConfig gameConfig)
			:gameConfig(gameConfig),
			 gameNetwork(Helper::getSocketAddr(gameConfig.serverAddr,
					 gameConfig.serverPort).c_str()),
			 game::EventListener() {
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Worm/texture.plist", "Worm/texture.png");
//        prepareGame();
		showLoginScene();
	}

	void login(const std::string& name) {
		gameNetwork.send(CMD::LOGIN, {name});
	}

	void addPlayer(const Player& player) {
		mapLogic.addUnit(player.worm);
		players.push_back(player);
	}

	void removePlayer(int id) {
		auto player = std::find_if(players.begin(), players.end(),
				[=](const Player& player) { return player.id == id; });
	}

	void removeAllPlayer() {
		players.clear();
	}

	void nextTurn(int id) {
		currentPlayer = std::find_if(players.begin(), players.end(),
				[=](const Player& player) { return player.id == id; });
	}

	void nextTurn() {
		++currentPlayer;
		if (currentPlayer == players.end()) { currentPlayer = players.begin(); }
	}

	void showLoginScene();

	void prepareGame() {
		gameState = WAITING;

		mapLogic.mapView->setVisible(false);
		guiLogin->setVisible(false);
		mapLogic.mapView->refreshMap();
		currentScene->schedule([=](float dt) {
		  mapLogic.update(dt);
		}, 0.0f, "update");

		const auto listener = cocos2d::EventListenerKeyboard::create();
		listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		  CCLOG("Key pressed");
		  if (gameState != PLAYING || currentPlayer != myPlayer) { return; }
		  auto worm = currentPlayer->worm;
		  if (worm->isStable) {
			  switch (keyCode) {
			  case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			  case EventKeyboard::KeyCode::KEY_A: worm->vy = 20;
				  worm->vx = -10;
				  break;
			  case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			  case EventKeyboard::KeyCode::KEY_D: worm->vy = 20;
				  worm->vx = 10;
				  break;
			  case EventKeyboard::KeyCode::KEY_UP_ARROW:
			  case EventKeyboard::KeyCode::KEY_W: worm->angle += 10;
				  worm->refreshIndicate();
				  break;
			  case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			  case EventKeyboard::KeyCode::KEY_S: worm->angle -= 10;
				  worm->refreshIndicate();
				  break;
			  case EventKeyboard::KeyCode::KEY_SPACE: mapLogic.addUnit(worm->makeBullet());
				  nextTurn();
				  break;
			  default: break;
			  }
		  }
		};
		listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		  if (gameState != PLAYING) { return; }
		  auto worm = currentPlayer->worm;
		  worm->ay = 0;
		  worm->ax = 0;
		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, currentScene);
		gameNetwork.send(2);
	}

	void startGame(int id) {
		gameState = PLAYING;
		mapLogic.mapView->refreshMap();

		nextTurn(id);
	}

	void restartGame(int id) {
		removeAllPlayer();
		startGame(id);
	}
};

#endif //WORM_GAME_H
