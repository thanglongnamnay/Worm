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
	CALCULATING,
};

class Game : game::EventListener {
private:
	GameConfig gameConfig;
	GameNetwork gameNetwork;
	MapLogic mapLogic{{1024, 512}};
	GameState gameState = WAITING;
	std::list<Player> players;
	std::list<Player>::iterator currentPlayer;
	std::list<Player>::iterator myPlayer;

	Scene* currentScene = nullptr;
	Node* guiLogin = nullptr;
	void handleEvent(int eventName, const Object& data) override;
	void handleNetworkCmd(CMD cmd, Params& params);
	void handleGameAction(Params params);
public:
	static Game* instance;
	explicit Game(GameConfig gameConfig);
	void update(float dt);
	void login(const std::string& name);
	void
	addPlayer(int id, const std::string& name, double x = rand() % 800, double y = 400 + rand() % 400, int hp = 100,
			int mp = 0, Angle angle = Angle(0));
	void removePlayer(Player* p);
	void removeAllPlayer();
	void nextTurn(int id);
	void nextTurn();
	void showLoginScene();
	void prepareGame();
	void startGame(int id);
	void restartGame(int id);
};

#endif //WORM_GAME_H
