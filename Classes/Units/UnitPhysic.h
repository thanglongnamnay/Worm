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
	int playerId = -1;
	double px = 0; // Position
	double py = 0;
	double vx = 0; // Velocity
	double vy = 0;
	double ax = 0; // Acceleration
	double ay = 0;
	double maxVx = 0;
	double maxVy = 0;

	double radius = 4;    // Bounding circle for collision
	bool isStable = false;    // Has object stopped moving
	double friction = 0.8;    // Actually, a dampening factor is a more accurate name

	int bounceBeforeDeath = -1;    // How many time object can bounce before death
	bool isDead = false;        // Flag to indicate object should be removed

	explicit UnitPhysic(double x = 0, double y = 0);
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
	CRT_UnitPhysic(double x, double y)
			:UnitPhysic(x, y) {
		view = ViewType::create();
	}

	void draw() override {
		if (view) view->setPosition(px, py);
	}
    Node* getView() override {
		return view.get();
	}
	~CRT_UnitPhysic() override = default;
};

class Missile : public CRT_UnitPhysic<MissileView> {
public:
	explicit Missile(double x, double y, const Angle& angle, double strength = 100);

	int bounceDeathAction() override;
};

class Debris : public CRT_UnitPhysic<DebrisView> {
public:
	explicit Debris(double x = 0, double y = 0);

	int bounceDeathAction() override;
};

class Worm : public CRT_UnitPhysic<WormView> {
public:
	Angle angle;
	explicit Worm(double x = 0, double y = 0, Angle angle = Angle(0));

	int bounceDeathAction() override;

	std::shared_ptr<Missile> makeBullet(int power);

	void refreshIndicate();
};

#endif //WORM_UNITPHYSIC_H
