//
// Created by long on 20/05/2020.
//

#include <cocos/2d/CCNode.h>
#include <Guis/GuiEndGame.h>
#include "Game.h"

Game* Game::instance = nullptr;
void Game::showLoginScene() {
	gameState = WAITING;
	currentScene = HelloWorld::create();
	auto runningScene = Director::getInstance()->getRunningScene();
	if (runningScene) {
		Director::getInstance()->replaceScene(currentScene);
		mapLogic.mapView->removeFromParent();
	}
	else {
		Director::getInstance()->runWithScene(currentScene);
	}

	currentScene->addChild(mapLogic.mapView);
	mapLogic.mapView->setVisible(false);
	guiLogin = GuiLogin::create();
	currentScene->addChild(guiLogin);
}
void Game::handleEvent(int eventName, const Object& data) {
	EventListener::handleEvent(eventName, data);
	if (eventName == event::EVENT_RECEIVE_PACKET) {
		auto cmd = any_cast<int>(data.at("cmd"));
		auto params = any_cast<Params>(data.at("params"));
		handleNetworkCmd(static_cast<CMD>(cmd), params);
		return;
	}
	if (eventName == event::EVENT_HIT) {
		auto shooter = any_cast<int>(data.at("shooter"));
		auto shot = any_cast<int>(data.at("shot"));
		auto shooterPlayer = find_if(players.begin(), players.end(), [&](const Player& p) {
			return p.id == shooter;
		});
		auto shotPlayer = find_if(players.begin(), players.end(), [&](const Player& p) {
			return p.id == shot;
		});
		shooterPlayer->shoot(*shotPlayer);
		return;
	}
	if (eventName == event::EVENT_PLAYER_DIE) {
		const auto id = any_cast<int>(data.at("id"));
		someoneDied = true;
		return;
	}
}
void Game::handleNetworkCmd(CMD cmd, Params& params) {
	CCLOG("handleNetworkCmd: %d", (int)cmd);
	switch (cmd) {
		case CMD::LOGIN:
			prepareGame();
			break;
		case CMD::JOIN_ROOM: {
			const auto seed = params.getInt();
			const auto id = params.getInt();
			const auto name = params.getString();
			const auto x = params.getDouble();
			const auto y = params.getDouble();
			const auto hp = params.getInt();
			const auto mp = params.getInt();
			const auto angle = Angle(params.getInt());

			mapLogic.recreateMap(seed);
			CCLOG("JOIN_ROOM: %d, %s, %f, %f, %d, %d", id, name.c_str(), x, y, hp, mp);
			addPlayer(id, name, x, y, hp, mp, angle);
			break;
		}
		case CMD::START: {
			const auto id = params.getInt();
			CCLOG("START: %d", id);
			startGame(id);
			break;
		}
		case CMD::YOUR_ID: {
			const auto id = params.getInt();
			isMaster = params.getBool();
			CCLOG("YOUR_ID: %d", id);
			myPlayer = find_if(players.begin(), players.end(), [=](const Player& p) { return p.id == id; });
			Player::myId = id;
			break;
		}
		case CMD::GAME_ACTION: {
			handleGameAction(params);
			break;
		}
		default:
			CCLOG("Unhandled case: %d", cmd);
			break;
			// TODO: implement this shit
	}
}
void Game::handleGameAction(Params params) {
	const auto id = params.getInt();
	CCLOG("GAME_ACTION: %d", id);
	const auto action = (GAME_ACTION)params.getInt();
	auto worm = currentPlayer->worm;
	switch (action) {
		case GAME_ACTION::SHOOT: {
			const auto power = params.getInt();
			mapLogic.addUnit(worm->makeBullet(power));
			needNextTurn = true;
			break;
		}
		case GAME_ACTION::CHANGE_ANGLE: {
			const auto angle = params.getInt();
			worm->angle = angle;
			worm->refreshIndicate();
			break;
		}
		case GAME_ACTION::MOVE: {
			const auto direction = params.getInt();
			worm->vy = 20;
			worm->vx = 10 * direction;
			break;
		}
		case GAME_ACTION::NEXT_TURN: {
			nextTurn(id);
			break;
		}
	}
}
Game::Game(GameConfig gameConfig)
		:gameConfig(gameConfig),
		 gameNetwork(Helper::getSocketAddr(gameConfig.serverAddr,
				 gameConfig.serverPort).c_str()),
		 game::EventListener() {
	GameNetwork::instance = &gameNetwork;
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Worm/texture.plist", "Worm/texture.png");
	showLoginScene();
}
void Game::login(const string& name) {
	gameNetwork.send(static_cast<int>(CMD::LOGIN), {name});
}
void Game::addPlayer(int id, const std::string& name, double x, double y, int hp, int mp, Angle angle) {
	players.emplace_back(mapLogic, id, name, x, y, hp, mp, angle);
	mapLogic.addUnit(players.back().worm);
}
void Game::removePlayer(Player* p) {
	mapLogic.removeUnit(p->worm);
}
void Game::removeAllPlayer() {
	players.clear();
}
void Game::nextTurn(int id) {
	currentPlayer = std::find_if(players.begin(), players.end(),
			[=](const Player& player) { return player.id == id; });
	gameState = PLAYING;
	if (currentPlayer == players.end()) throw bad_any_cast();
}
void Game::nextTurn() {
	++currentPlayer;
	if (currentPlayer == players.end()) { currentPlayer = players.begin(); }
	gameState = PLAYING;
}
void Game::prepareGame() {
	gameState = WAITING;

	mapLogic.mapView->setVisible(false);
	guiLogin->setVisible(false);
	mapLogic.mapView->refreshMap();
	currentScene->schedule([=](float dt) {
		update(dt);
	}, 0.016f, "update");

	const auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		CCLOG("Key pressed");
		if (gameState != PLAYING || currentPlayer->id != myPlayer->id) { return; }
		auto worm = currentPlayer->worm;
		if (worm->isStable) {
			switch (keyCode) {
				case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
				case EventKeyboard::KeyCode::KEY_A:
					gameNetwork.send(static_cast<int>(CMD::GAME_ACTION),
							{currentPlayer->id, static_cast<int>(GAME_ACTION::MOVE), -1});
					break;
				case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
				case EventKeyboard::KeyCode::KEY_D:
					gameNetwork.send(static_cast<int>(CMD::GAME_ACTION),
							{currentPlayer->id, static_cast<int>(GAME_ACTION::MOVE), 1});
					break;
				case EventKeyboard::KeyCode::KEY_UP_ARROW:
				case EventKeyboard::KeyCode::KEY_W:
					gameNetwork.send(static_cast<int>(CMD::GAME_ACTION),
							{currentPlayer->id, static_cast<int>(GAME_ACTION::CHANGE_ANGLE),
							 static_cast<int>(worm->angle) + 10});
					break;
				case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
				case EventKeyboard::KeyCode::KEY_S:
					gameNetwork.send(static_cast<int>(CMD::GAME_ACTION),
							{currentPlayer->id, static_cast<int>(GAME_ACTION::CHANGE_ANGLE),
							 static_cast<int>(worm->angle) - 10});
					break;
				case EventKeyboard::KeyCode::KEY_SPACE:
					gameNetwork.send(static_cast<int>(CMD::GAME_ACTION), {
							currentPlayer->id,
							static_cast<int>(GAME_ACTION::SHOOT),
							mapLogic.mapView->getPower(),
					});
					gameState = CALCULATING;
					break;
				default:
					break;
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
void Game::startGame(int id) {
	gameState = PLAYING;
	mapLogic.mapView->refreshMap();

	nextTurn(id);
}
void Game::restartGame(int id) {
	gameState = WAITING;
	if (id >= 0) {
		auto winPlayer = find_if(players.begin(), players.end(), [=](const Player& p) { return p.id == id; });
		currentScene->addChild(GuiEndGame::create(winPlayer->name));
	}
	else {
		currentScene->addChild(GuiEndGame::create());
	}
	removeAllPlayer();
//	showLoginScene();
}
void Game::update(float dt) {
	if (gameState == WAITING) return;
	if (players.size() < 2) {
		restartGame(!players.empty() ? players.front().id : -1);
	} else {
		mapLogic.update(dt);
	}
	if (someoneDied) {
		someoneDied = false;
		players.remove_if([=](const Player& p) { return p.hp <= HP(0); });
	}
	if (needNextTurn) {
		needNextTurn = false;
		nextTurn();
	}
}
