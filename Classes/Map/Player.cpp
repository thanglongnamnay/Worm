//
// Created by MacBook Pro on 6/24/20.
//

#include <GameNetwork.h>
#include "Player.h"

Player::Player(MapLogic& mapLogic, int id, const std::string& name, int x, int y, int hp, int mp, Angle angle)
		:
		id(id),
		name(name),
		hp(hp),
		mp(mp),
		damage(55),
		mapLogic(mapLogic),
		worm(std::make_shared<Worm>(Vec2(x, y), angle)) {
	worm->playerId = id;
	worm->view->setPlayerName(name);
}
void Player::onDead() {
	worm->isDead = true;
	game::EventManager::emit(EVENT_PLAYER_DIE, (Object){
			{"id", id},
	});
}
void Player::init() {
	hp = HP(100);
	mp = MP(0);
}
void Player::shoot(Player& other) {
	other.hp -= damage;
	other.worm->view->changeHp(static_cast<int>(other.hp));
	CCLOG("SHOOT: -%d => %d", static_cast<int>(damage), static_cast<int>(other.hp));
	if (other.hp <= HP(0)) {
		other.hp = HP(0);
		other.onDead();
	}
}
void Player::sync() const {
	if (worm) {
		GameNetwork::instance->send(static_cast<int>(CMD::SYNC_PLAYER), {
				to_string(id),
				to_string(worm->position.x),
				to_string(worm->position.y),
				to_string(static_cast<int>(hp)),
				to_string(static_cast<int>(mp)),
				to_string(static_cast<int>(worm->angle)),
		});
	} else {
		GameNetwork::instance->send(static_cast<int>(CMD::SYNC_PLAYER), {
				to_string(id),
				to_string(0),
				to_string(0),
				to_string(static_cast<int>(hp)),
				to_string(static_cast<int>(mp)),
				to_string(static_cast<int>(0)),
		});
	}
}
