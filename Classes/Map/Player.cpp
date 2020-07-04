//
// Created by MacBook Pro on 6/24/20.
//

#include <GameNetwork.h>
#include "Player.h"
int Player::myId = -1;
Player::Player(int id, std::string name, int x, int y, int hp, int mp, Angle angle)
		:
		id(id),
		name(std::move(name)),
		hp(hp),
		mp(mp),
		damage(55),
		worm(std::make_shared<Worm>(x, y, angle)) {
	worm->playerId = id;
}
void Player::onDead() {
	worm->isDead = true;
}
void Player::init() {
	hp = HP(100);
	mp = MP(0);
}
void Player::shoot(Player& other) {
	other.hp -= damage;
	other.worm->view->changeHp(static_cast<int>(hp));
	if (other.hp <= HP(0)) {
		other.hp = HP(0);
		other.onDead();
	}
}
void Player::sync() {
	GameNetwork::instance->send(static_cast<int>(CMD::SYNC_PLAYER), {
			to_string(id),
			to_string(worm->px),
			to_string(worm->py),
			to_string(static_cast<int>(hp)),
			to_string(static_cast<int>(mp)),
			to_string(static_cast<int>(worm->angle)),
	});
}
