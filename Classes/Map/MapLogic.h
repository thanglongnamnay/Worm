//
// Created by long on 22/05/2020.
//

#ifndef WORM_MAPLOGIC_H
#define WORM_MAPLOGIC_H

#include <Types/Vector.h>
#include <vector>
#include <Units/UnitLogic.h>
#include "MapView.h"

class MapLogic {
private:
    type::Vector<int> mapSize;
    std::vector<std::vector<unsigned char>> map;
    std::list<std::unique_ptr<UnitLogic>> unitList;
public:
    MapView* mapView;

    explicit MapLogic(type::Vector<int> mapSize);

    MapLogic(MapLogic&& rhs) noexcept
            :mapSize(rhs.mapSize), map(std::move(rhs.map)), mapView(rhs.mapView) {
    }

    void addUnit(std::unique_ptr<UnitLogic> unitLogic) {
        unitLogic->draw();
        mapView->addChild(unitLogic->view);
        unitList.push_back(std::move(unitLogic));
    }

    void update(double dt) {
    	dt *= 10;
        for (auto& p : unitList) {
            // Apply Gravity
            p->ay -= 9.81;

            // Update Velocity
            p->vx += p->ax*dt;
            p->vy += p->ay*dt;

            // Update Position
            double potentialX = p->px+p->vx*dt;
            double potentialY = p->py+p->vy*dt;

            // Reset Acceleration
            p->ax = 0;
            p->ay = 0;
            p->isStable = false;

            // Collision Check With Map
            double angle = atan2f(p->vy, p->vx);
            double responseX = 0;
            double responseY = 0;
            bool collision = false;

            // Iterate through semicircle of objects radius rotated to direction of travel
            for (auto r = angle-3.14159/2; r<angle+3.14159/2; r += 3.14159/8) {
                // Calculate test point on circumference of circle
                double testPosX = (p->radius)*cosf(r)+potentialX;
                double testPosY = (p->radius)*sinf(r)+potentialY;

                // Constrain to test within map boundary
                if (testPosX>=mapSize.x) { testPosX = mapSize.x-1; }
                if (testPosY>=mapSize.y) { testPosY = mapSize.y-1; }
                if (testPosX<0) { testPosX = 0; }
                if (testPosY<0) { testPosY = 0; }

                // Test if any points on semicircle intersect with terrain
                if (map[(int)testPosY][(int)testPosX]!=0) {
                    // Accumulate collision points to give an escape response vector
                    // Effectively, normal to the areas of contact
                    responseX += potentialX-testPosX;
                    responseY += potentialY-testPosY;
//                    CCLOG("Collision: %f, %f", testPosX, testPosY);
                    collision = true;
                }
            }

            // Calculate magnitudes of response and velocity vectors
            double magVelocity = sqrtf(p->vx*p->vx+p->vy*p->vy);
            double magResponse = sqrtf(responseX*responseX+responseY*responseY);

            // Collision occurred
            if (collision) {
                // Force object to be stable, this stops the object penetrating the terrain
                p->isStable = true;

                // Calculate reflection vector of objects velocity vector, using response vector as normal
                double dot = p->vx*(responseX/magResponse)+p->vy*(responseY/magResponse);

                // Use friction coefficient to dampen response (approximating energy loss)
                p->vx = p->friction*(-2*dot*(responseX/magResponse)+p->vx);
                p->vy = p->friction*(-2*dot*(responseY/magResponse)+p->vy);

                //Some objects will "die" after several bounces
                if (p->bounceBeforeDeath>0) {
                    p->bounceBeforeDeath--;
                    p->isDead = p->bounceBeforeDeath==0;

                    // If object died, work out what to do next
                    if (p->isDead) {
                        // Action upon object death
                        // = 0 Nothing
                        // > 0 Explosion
                        int nResponse = p->BounceDeathAction();
                        if (nResponse>0) {
                           // Boom(p->px, p->py, nResponse);
                        }
                    }
                }

            }
            else {
                // No collision so update objects position
                p->px = potentialX;
                p->py = potentialY;
            }

            // Turn off movement when tiny
//			CCLOG("POTENTIAL: %f, %f", potentialX, potentialY);
//			CCLOG("POS: %f, %f", p->px, p->py);
            if (magVelocity<0.1f) { p->isStable = true; }
            p->draw();
        }

        // Remove dead objects from the list, so they are not processed further. As the object
        // is a unique pointer, it will go out of scope too, deleting the object automatically. Nice :-)
        unitList.remove_if([](std::unique_ptr<UnitLogic>& o) { return o->isDead; });
    }

private:
    static std::vector<std::vector<unsigned char>> createMap(type::Vector<int> mapSize) {
        auto fNoiseSeed = std::vector<double>(static_cast<int>(mapSize.x));
        for (int i = 0; i<mapSize.x; i++) {
            fNoiseSeed[i] = (double)rand()/RAND_MAX;
        }
        fNoiseSeed[0] = 0.5f;
        auto fSurface = PerlinNoise1D(fNoiseSeed, 8, 2);
        std::vector<std::vector<unsigned char>> map(mapSize.y);
        for (auto y = 0; y<mapSize.y; ++y) {
            map[y] = std::vector<unsigned char>(mapSize.x);
            for (auto x = 0; x<mapSize.x; ++x) {
                map[y][x] = y < fSurface[x]*mapSize.y;
//                map[y][x] = 0;
            }
        }
        return map;
    }

    static std::vector<double> PerlinNoise1D(std::vector<double> fSeed, int nOctaves, double fBias);
};

#endif //WORM_MAPLOGIC_H
