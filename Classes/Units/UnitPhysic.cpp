//
// Created by long on 20/05/2020.
//

#include "UnitPhysic.h"

UnitPhysic::UnitPhysic(const Vec2& position)
        : position(position) {
}

void UnitPhysic::update(double dt, const std::vector<std::vector<unsigned char>> &map) {
    if (velocity.length() < epsilon && acceleration.length() < epsilon && isStable) return draw();
    velocity += (acceleration + GRAVITY) * dt;

    if (velocity.x < epsilon && velocity.x > -epsilon) velocity.x = 0;
    if (velocity.y < epsilon && velocity.y > -epsilon) velocity.y = 0;

    Vec2 potential = position + velocity * dt;

    isStable = false;

    // Collision Check With Map
    double angle = atan2(velocity.y, velocity.x);
    Vec2 respond{0, 0};
    bool collision = false;

    // Iterate through semicircle of objects radius rotated to direction of travel
	auto PI = 3.14159;
	for (auto r = angle - PI / 2; r < angle + PI / 2; r += PI / 8) {
        // Calculate test point on circumference of circle
        Vec2 testPos = potential + Vec2(radius * cos(r),radius * sin(r));

        // Constrain to test within map boundary
        const auto sizeX = map[0].size();
        const auto sizeY = map.size();
        if (testPos.y >= sizeY) testPos.y = sizeY - 1;
        if (testPos.x >= sizeX || testPos.y >= sizeY || testPos.y < 0 || map[(int)testPos.y][(int)testPos.x] != 0) {
            // Accumulate collision points to give an escape response vector
            // Effectively, normal to the areas of contact
            respond += potential - testPos;
            collision = true;
        }
    }

    // Calculate magnitudes of response and velocity vectors
    double magVelocity = velocity.length();
    double magResponse = respond.length();

    // Collision occurred
    if (collision) {
        // Force object to be stable, this stops the object penetrating the terrain
        isStable = true;

        // Calculate reflection vector of objects velocity vector, using response vector as normal
        double dot = velocity.dot(respond) / magResponse;

        // Use friction coefficient to dampen response (approximating energy loss)
        velocity = friction * (velocity - 2 * dot * (respond / magResponse));

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
        position = potential;
    }

    if (magVelocity < epsilon) { isStable = true; }
    draw();
}

Missile::Missile(const Vec2& position, const Angle &angle, double strength)
        :CRT_UnitPhysic(position) {
    radius = 2;
    friction = 0.5;

    velocity.x = strength * cos(static_cast<double>(angle) * 3.14 / 180);
    velocity.y = strength * sin(static_cast<double>(angle) * 3.14 / 180);
    bounceBeforeDeath = 1;
}

int Missile::bounceDeathAction() {
    return 20; // Explode Big
}

Debris::Debris(const Vec2& position)
        :CRT_UnitPhysic(position) {
    // Set velocity to random direction and size for "boom" effect
    velocity.x = 30 * cos((double)rand() / (double)RAND_MAX * 2 * 3.14159f);
    velocity.y = 30 * sin((double)rand() / (double)RAND_MAX * 2 * 3.14159f);
    radius = 1;
    friction = 0.8;
    bounceBeforeDeath = 1; // After 5 bounces, dispose
}

int Debris::bounceDeathAction() {
    return 0; // Nothing, just fade
}

Worm::Worm(const Vec2& position, Angle angle)
        :CRT_UnitPhysic(position), angle(angle) {
    radius = 5;
    friction = 0.2;
    bounceBeforeDeath = -1;
    view->indicate(0);
    flip(true);
}

int Worm::bounceDeathAction() {
    return 0;
}

std::shared_ptr<Missile> Worm::makeBullet(int power) {
    auto missile = std::make_shared<Missile>(position, angle, power);
    missile->playerId = playerId;
    return missile;
}

void Worm::refreshIndicate() {
    view->indicate(angle);
}
void Worm::flip(bool v) {
	if (v == fliped) return;
	fliped = v;
	view->flip(!v);
	angle = Angle(180) - angle;
	refreshIndicate();
}
Angle Worm::raiseAngle(double amount) const {
	if (fliped) {
		return MAX(Angle(static_cast<double>(angle) - amount), Angle::RIGHT_ANGLE);
	}
	return MIN(Angle(static_cast<double>(angle) + amount), Angle::RIGHT_ANGLE);
}
