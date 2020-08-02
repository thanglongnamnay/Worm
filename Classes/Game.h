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
#include <Map/Player.h>

#include "Types/HP.h"
#include "Types/MP.h"

enum GameState {
	WAITING,
	PLAYING,
	CALCULATING,
};

class Game : game::EventListener {
private:
	GameConfig gameConfig;
	GameNetwork gameNetwork;
	MapLogic mapLogic{{2048, 512}};
	GameState gameState = WAITING;
	list<Player> players;
	list<Player>::iterator currentPlayer;
	list<Player>::iterator myPlayer;
	bool someoneDied{};
	bool needNextTurn{};

	Scene* currentScene = nullptr;
	Node* guiLogin = nullptr;
	void handleEvent(int eventName, const Object& data) override;
	void handleNetworkCmd(CMD cmd, Params& params);
	void handleGameAction(Params params);
public:
	static Game* instance;
	explicit Game(GameConfig gameConfig);
	void update(float dt);
	void login(const string& name);
	const Player&
	addPlayer(int id, const string& name, double x = rand() % 800, double y = 400 + rand() % 400, int hp = 100,
			int mp = 0, Angle angle = Angle(0));
	void removePlayer(Player* p);
	void removeAllPlayer();
	void nextTurn(int id);
	void nextTurn();
	void showLoginScene();
	void prepareGame();
	void startGame(int id);
	void restartGame(int id);
	void onDisconnect();
};

#endif //WORM_GAME_H
