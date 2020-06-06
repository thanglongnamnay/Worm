//
// Created by long on 20/05/2020.
//

#ifndef WORM_UNITLOGIC_H
#define WORM_UNITLOGIC_H

#include "UnitView.h"

class UnitLogic {
private:
public:
    Node* view = nullptr;
    double px = 0; // Position
    double py = 0;
    double vx = 0; // Velocity
    double vy = 0;
    double ax = 0; // Acceleration
    double ay = 0;

    double radius = 4;    // Bounding circle for collision
    bool isStable = false;    // Has object stopped moving
    double friction = 0.8;    // Actually, a dampening factor is a more accurate name

    int bounceBeforeDeath = -1;    // How many time object can bounce before death
    bool isDead = false;        // Flag to indicate object should be removed

    explicit UnitLogic(double x = 0, double y = 0)
            :px(x), py(y) {
		const int numberSprite = 15;
		view = Sprite::createWithSpriteFrameName("tile000.png");
		view->setPosition(300, 300);

		Vector<SpriteFrame*> animFrames;
		animFrames.reserve(numberSprite);

		for (auto i = 0; i < numberSprite; ++i) {
			if (i < 10) {
				animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tile00" + std::to_string(i) + ".png"));
			} else {
				animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("tile0" + std::to_string(i) + ".png"));
			}
		}

		Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		Animate* animate = Animate::create(animation);

		view->runAction(RepeatForever::create(animate));
    }

    virtual ~UnitLogic() {
        if (view) { view->removeFromParent(); }
    }

    void draw() {
        if (view) { view->setPosition(px, py); }
    }

    virtual int BounceDeathAction() = 0;
};

class Missile : public UnitLogic {
public:
    explicit Missile(float x = 0, float y = 0, float _vx = 0, float _vy = 0)
            :UnitLogic(x, y) {
        radius = 2;
        friction = 0.5;
        vx = _vx;
        vy = _vy;
        isDead = false;
        bounceBeforeDeath = 10;
    }

    int BounceDeathAction() override {
        return 20; // Explode Big
    }
};

class Debris : public UnitLogic {
public:
    explicit Debris(double x = 0, double y = 0)
            :UnitLogic(x, y) {
        // Set velocity to random direction and size for "boom" effect
        vx = 10*cosf(((double)rand()/(double)RAND_MAX)*2*3.14159f);
        vy = 10*sinf(((double)rand()/(double)RAND_MAX)*2*3.14159f);
        radius = 1;
        friction = 0.8;
        bounceBeforeDeath = 5; // After 5 bounces, dispose
    }

    int BounceDeathAction() override {
        return 0; // Nothing, just fade
    }
};

class Worm : public UnitLogic {
public:
    explicit Worm(float x = 0, float y = 0)
            :UnitLogic(x, y) {
        radius = 3.5;
        friction = 0.2;
        isDead = false;
        bounceBeforeDeath = -1;
    }

    int BounceDeathAction() override {
        return 0;
    }
};

#endif //WORM_UNITLOGIC_H
