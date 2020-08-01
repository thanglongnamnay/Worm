//
// Created by long on 20/05/2020.
//

#ifndef WORM_UNITPHYSIC_H
#define WORM_UNITPHYSIC_H

#include <GameEvent.h>
#include "UnitView.h"

class UnitPhysic {
private:
	constexpr static const double epsilon = 0.1;
public:
    const Vec2 GRAVITY{0, -9.8};
	int playerId = -1;
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	double radius = 4;    // Bounding circle for collision
	bool isStable = false;    // Has object stopped moving
	double friction = 0.8;    // Actually, a dampening factor is a more accurate name

	int bounceBeforeDeath = -1;    // How many time object can bounce before death
	bool isDead = false;        // Flag to indicate object should be removed

	explicit UnitPhysic(const Vec2& position);
	virtual ~UnitPhysic() = default;

	virtual void update(double dt, const std::vector<std::vector<unsigned char>>& map);
	virtual void draw() = 0;
	virtual int bounceDeathAction() = 0;
	virtual Node* getView() = 0;
};

template<class ViewType>
class CRT_UnitPhysic : public UnitPhysic {
public:
    std::shared_ptr<ViewType> view;
	explicit CRT_UnitPhysic(const Vec2& position)
			:UnitPhysic(position) {
		view = ViewType::create();
	}

	void draw() override {
		if (view) view->setPosition(position);
	}
    Node* getView() override {
		return view.get();
	}
	~CRT_UnitPhysic() override = default;
};

class Missile : public CRT_UnitPhysic<MissileView> {
public:
	explicit Missile(const Vec2& position, const Angle& angle, double strength = 100);

	int bounceDeathAction() override;
};

class Debris : public CRT_UnitPhysic<DebrisView> {
public:
	explicit Debris(const Vec2& position = Vec2::ZERO);

	int bounceDeathAction() override;
};

class Worm : public CRT_UnitPhysic<WormView> {
	bool fliped;
public:
	Angle angle;
	explicit Worm(const Vec2& position = Vec2::ZERO, Angle angle = Angle(0));

	int bounceDeathAction() override;

	std::shared_ptr<Missile> makeBullet(int power);

	void refreshIndicate();

	void flip(bool);
};

#endif //WORM_UNITPHYSIC_H
