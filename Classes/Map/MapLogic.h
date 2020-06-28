//
// Created by long on 22/05/2020.
//

#ifndef WORM_MAPLOGIC_H
#define WORM_MAPLOGIC_H

#include <Types/Vector.h>
#include <vector>
#include <GameEvent.h>
#include <Units/UnitPhysic.h>
#include <Packet.h>
#include <GameNetwork.h>
#include "MapView.h"
#include "Player.h"

constexpr const double epsilon = 0.001;

class MapLogic : game::EventListener {
private:
    void handleEvent(int eventName, const Object &data) override;
    void handleNetworkCmd(CMD cmd);

    type::Vector<int> mapSize;
    std::vector<std::vector<unsigned char>> map;
    std::list<std::shared_ptr<UnitPhysic>> unitList;
    std::vector<Player> players;
    std::shared_ptr<Worm> worm;
public:
    MapView *mapView;

    explicit MapLogic(type::Vector<int> mapSize);

    MapLogic(MapLogic &&rhs) noexcept
            : mapSize(rhs.mapSize), map(std::move(rhs.map)), mapView(rhs.mapView) {
    }

    void addUnit(const std::shared_ptr<UnitPhysic> &UnitPhysic) {
        UnitPhysic->draw();
        mapView->addChild(UnitPhysic->view);
        unitList.push_back(UnitPhysic);
    }

    void update(double dt) {
        dt *= 10;
        for (auto &p : unitList) {
            p->update(dt, map);
        }

        // Remove dead objects from the list, so they are not processed further. As the object
        // is a unique pointer, it will go out of scope too, deleting the object automatically. Nice :-)
        unitList.remove_if([](const std::shared_ptr<UnitPhysic>& o) { return o->isDead; });
    }

    void nextTurn(int id) {

    }

private:
    void drawLine(const int sx, const int ex, const int ny) {
        if (ny < 0) return;
        for (int i = sx; i < ex; i++) {
            if (ny < mapSize.y && i >= 0 && i < mapSize.x) {
                map[ny][i] = 0;
                mapView->refreshMap(i, ny);
            }
        }
    }
    void CircleBresenham(int xc, int yc, int r) {
        int x = 0;
        int y = r;
        int p = 3 - 2 * r;
        if (!r) return;

        while (y >= x) {
            // Modified to draw scan-lines instead of edges
            drawLine(xc - x, xc + x, yc - y);
            drawLine(xc - y, xc + y, yc - x);
            drawLine(xc - x, xc + x, yc + y);
            drawLine(xc - y, xc + y, yc + x);
            if (p < 0) p += 4 * x++ + 6;
            else p += 4 * (x++ - y--) + 10;
        }
    };
    void explode(double worldX, double worldY, double radius) {
        CircleBresenham(worldX, worldY, radius);

        for (auto &p : unitList) {
            double dx = p->px - worldX;
            double dy = p->py - worldY;
            double distance = sqrt(dx * dx + dy * dy);
            if (distance < epsilon) distance = epsilon;

            if (distance < radius) {
                p->vx = 10 * (dx / distance) * radius;
                p->vy = 10 * (dy / distance) * radius;
                p->isStable = false;
            }
        }

        // Launch debris proportional to blast size
        for (int i = 0; i < (int) radius; i++)
            addUnit(std::make_shared<Debris>(worldX, worldY));

        mapView->refreshMap();
    }

    static std::vector<std::vector<unsigned char>> createMap(type::Vector<int> mapSize) {
        auto fNoiseSeed = std::vector<double>(static_cast<int>(mapSize.x));
        srand(time(0));
        for (int i = 0; i < mapSize.x; i++) {
            fNoiseSeed[i] = (double) rand() / RAND_MAX;
        }
        fNoiseSeed[0] = 0.5f;
        auto fSurface = PerlinNoise1D(fNoiseSeed, 8, 2);
        std::vector<std::vector<unsigned char>> map(mapSize.y);
        for (auto y = 0; y < mapSize.y; ++y) {
            map[y] = std::vector<unsigned char>(mapSize.x);
            for (auto x = 0; x < mapSize.x; ++x) {
                map[y][x] = y < fSurface[x] * mapSize.y;
//                map[y][x] = 0;
            }
        }
        return map;
    }

    static std::vector<double> PerlinNoise1D(std::vector<double> fSeed, int nOctaves, double fBias);
};

#endif //WORM_MAPLOGIC_H
