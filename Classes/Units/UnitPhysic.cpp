//
// Created by long on 20/05/2020.
//

#include "UnitPhysic.h"

UnitPhysic::UnitPhysic(double x, double y)
        :px(x), py(y) {
}

void UnitPhysic::update(double dt, const std::vector<std::vector<unsigned char>> &map) {
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
        if (testPosY >= sizeY) testPosY = sizeY - 1;
        if (testPosX >= sizeX || testPosY >= sizeY || testPosY < 0 || map[(int)testPosY][(int)testPosX] != 0) {
            // Accumulate collision points to give an escape response vector
            // Effectively, normal to the areas of contact
            responseX += potentialX - testPosX;
            responseY += potentialY - testPosY;
            collision = true;
        }
    }

    // Calculate magnitudes of response and velocity vectors
    double magVelocity = sqrt(vx * vx + vy * vy);
    double magResponse = sqrt(responseX * responseX + responseY * responseY);

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
                int response = bounceDeathAction();
                if (response > 0) {
                    game::EventManager::emit(EVENT_EXPLODE, (Object){
                            {"unit",    this},
                            {"respond", response},
                    });
                }
            }
        }

    }
    else {
        // No collision so update objects position
        px = potentialX;
        py = potentialY;
    }

    if (magVelocity < epsilon) { isStable = true; }
    draw();
}

Missile::Missile(double x, double y, const Angle &angle, double strength)
        :CRT_UnitPhysic(x, y) {
    radius = 2;
    friction = 0.5;

    vx = strength * cos(static_cast<double>(angle) * 3.14 / 180);
    vy = strength * sin(static_cast<double>(angle) * 3.14 / 180);
    bounceBeforeDeath = 1;
}

int Missile::bounceDeathAction() {
    return 20; // Explode Big
}

Debris::Debris(double x, double y)
        :CRT_UnitPhysic(x, y) {
    // Set velocity to random direction and size for "boom" effect
    vx = 30 * cos((double)rand() / (double)RAND_MAX * 2 * 3.14159f);
    vy = 30 * sin((double)rand() / (double)RAND_MAX * 2 * 3.14159f);
    radius = 1;
    friction = 0.8;
    bounceBeforeDeath = 1; // After 5 bounces, dispose
}

int Debris::bounceDeathAction() {
    return 0; // Nothing, just fade
}

Worm::Worm(double x, double y, Angle angle)
        :CRT_UnitPhysic(x, y), angle(angle) {
    radius = 5;
    friction = 0.2;
    bounceBeforeDeath = -1;
    view->indicate(0);
}

int Worm::bounceDeathAction() {
    return 0;
}

std::shared_ptr<Missile> Worm::makeBullet(int power) {
    auto missile = std::make_shared<Missile>(px, py, angle, power);
    missile->playerId = playerId;
    return missile;
}

void Worm::refreshIndicate() {
    view->indicate(angle);
}
