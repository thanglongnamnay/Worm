//
// Created by long on 20/05/2020.
//

#ifndef WORM_UNITPHYSIC_H
#define WORM_UNITPHYSIC_H

#include <GameEvent.h>
#include "UnitView.h"

const int EVENT_EXPLODE = game::EventManager::nextId();

class UnitPhysic {
private:
    constexpr static const double epsilon = 0.1;
public:
    UnitView *view = nullptr;
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

    explicit UnitPhysic(double x = 0, double y = 0)
            : px(x), py(y) {
    }
    virtual ~UnitPhysic() {
        if (view)
            try {
                view->removeFromParent();
            } catch(std::exception& e) {

            }
    }

    virtual void update(double dt, const std::vector<std::vector<unsigned char>> &map) {
        vx += ax * dt;
        vy += (ay - 10) * dt;

        if (vx < epsilon && vx > -epsilon) vx = 0;
        if (vy < epsilon && vy > -epsilon) vy = 0;

        double potentialX = px + vx * dt;
        double potentialY = py + vy * dt;

        isStable = false;

        // Collision Check With Map
        double angle = atan2(vy, vx);
        double responseX = 0;
        double responseY = 0;
        bool collision = false;

        // Iterate through semicircle of objects radius rotated to direction of travel
        for (auto r = angle - 3.14159 / 2; r < angle + 3.14159 / 2; r += 3.14159 / 8) {
            // Calculate test point on circumference of circle
            double testPosX = radius * cos(r) + potentialX;
            double testPosY = radius * sin(r) + potentialY;

            // Constrain to test within map boundary
            const auto sizeX = map[0].size();
            const auto sizeY = map.size();
            if (testPosX >= sizeX) { testPosX = sizeX - 1; }
            if (testPosY >= sizeY) { testPosY = sizeY - 1; }
            if (testPosX < 0) { testPosX = 0; }
            if (testPosY < 0) { testPosY = 0; }

            // Test if any points on semicircle intersect with terrain
            if (map[(int) testPosY][(int) testPosX] != 0) {
                // Accumulate collision points to give an escape response vector
                // Effectively, normal to the areas of contact
                responseX += potentialX - testPosX;
                responseY += potentialY - testPosY;
                collision = true;
            }
        }

        // Calculate magnitudes of response and velocity vectors
        double magVelocity = sqrtf(vx * vx + vy * vy);
        double magResponse = sqrtf(responseX * responseX + responseY * responseY);

        // Collision occurred
        if (collision) {
            // Force object to be stable, this stops the object penetrating the terrain
            isStable = true;

            // Calculate reflection vector of objects velocity vector, using response vector as normal
            double dot = vx * (responseX / magResponse) + vy * (responseY / magResponse);

            // Use friction coefficient to dampen response (approximating energy loss)
            vx = friction * (-2 * dot * (responseX / magResponse) + vx);
            vy = friction * (-2 * dot * (responseY / magResponse) + vy);

            //Some objects will "die" after several bounces
            if (bounceBeforeDeath > 0) {
                bounceBeforeDeath--;
                isDead = bounceBeforeDeath == 0;

                // If object died, work out what to do next
                if (isDead) {
                    // Action upon object death
                    // = 0 Nothing
                    // > 0 Explosion
                    int response = bounceDeathAction();
                    if (response > 0) {
                        // Boom(px, py, response);
                        Object data{
                                {"unit",    this},
                                {"respond", response},
                        };
                        game::EventManager::emit(EVENT_EXPLODE, data);
                        CCLOG("Emited %d", std::any_cast<UnitPhysic*>(data.at("unit"))->isDead);
                    }
                }
            }

        } else {
            // No collision so update objects position
            px = potentialX;
            py = potentialY;
        }

        // Turn off movement when tiny
//			CCLOG("POTENTIAL: %f, %f", potentialX, potentialY);
//			CCLOG("POS: %f, %f", px, py);
        if (magVelocity < 0.1) { isStable = true; }
        draw();
    }

    virtual void draw() {
        if (view) { view->setPosition(px, py); }
    }

    virtual int bounceDeathAction() = 0;
};

class Missile : public UnitPhysic {
public:
    explicit Missile(float x = 0, float y = 0, float _vx = 0, float _vy = 0)
            : UnitPhysic(x, y) {
        radius = 2;
        friction = 0.5;
        vx = _vx;
        vy = _vy;
        bounceBeforeDeath = 1;
        view = MissileView::create();
    }

    int bounceDeathAction() override {
        return 20; // Explode Big
    }
};

class Debris : public UnitPhysic {
public:
    explicit Debris(double x = 0, double y = 0)
            : UnitPhysic(x, y) {
        // Set velocity to random direction and size for "boom" effect
        vx = 30 * cos((double) rand() / (double) RAND_MAX * 2 * 3.14159f);
        vy = 30 * sin((double) rand() / (double) RAND_MAX * 2 * 3.14159f);
        radius = 1;
        friction = 0.8;
        bounceBeforeDeath = 1; // After 5 bounces, dispose
        view = DebrisView::create();
    }

    int bounceDeathAction() override {
        return 0; // Nothing, just fade
    }
};

class Worm : public UnitPhysic {
    double angle;
public:
    explicit Worm(float x = 0, float y = 0)
            : UnitPhysic(x, y), angle(0) {
        radius = 5;
        friction = 0.2;
        bounceBeforeDeath = -1;
        view = WormView::create();
    }

    int bounceDeathAction() override {
        return 0;
    }

    std::shared_ptr<Missile> make_bullet() {
        return std::make_shared<Missile>(px, py, 20, 20);
    }

    void draw() override {
        UnitPhysic::draw();
        ((WormView *) view)->indicate(45);
    }
};

#endif //WORM_UNITPHYSIC_H
