//
// Created by MacBook Pro on 6/24/20.
//

#ifndef WORM_PLAYER_H
#define WORM_PLAYER_H

#include <string>
#include <utility>
#include <Types/MP.h>
#include <Types/HP.h>
#include <Units/UnitPhysic.h>
#include "MapLogic.h"

class Player {
public:
	static int myId;
	const int id;
	const std::string name;
	const std::shared_ptr<Worm> worm;
	MapLogic& mapLogic;
	HP hp;
	MP mp;

	const HP damage;

	Player(MapLogic& mapLogic, int id, const std::string& name, int x = rand() % 800, int y = 400 + rand() % 400, int hp = 100, int mp = 0,
			Angle angle = Angle(0));
	void shoot(Player& other);
	void onDead();
	void init();
	void sync() const;

	~Player() {
		mapLogic.removeUnit(worm);
	}
};

#endif //WORM_PLAYER_H
