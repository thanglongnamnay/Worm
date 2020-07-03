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

    int seed;
	type::Vector<int> mapSize;
    std::vector<std::vector<unsigned char>> map;
    std::list<std::shared_ptr<UnitPhysic>> unitList;
public:
    MapView *mapView;

    explicit MapLogic(type::Vector<int> mapSize);

    MapLogic(MapLogic &&rhs) noexcept
            : mapSize(rhs.mapSize), map(std::move(rhs.map)), mapView(rhs.mapView) {
    }

    void recreateMap(int newSeed) {
    	if (newSeed == seed) return;
    	seed = newSeed;
    	srand(seed);
		map = createMap(mapSize);
		const auto& viewParent = mapView->getParent();
		for (const auto& unit : unitList) unit->view->removeFromParent();
		mapView->removeFromParent();
		mapView = MapView::create(map);
		viewParent->addChild(mapView);
		for (const auto& unit : unitList) mapView->addChild(unit->view);
		mapView->refreshMap();
    }

    void addUnit(const std::shared_ptr<UnitPhysic> &unitPhysic) {
        unitPhysic->draw();
        mapView->addChild(unitPhysic->view);
        unitList.push_back(unitPhysic);
    }
    void removeUnit(const std::shared_ptr<UnitPhysic> &unitPhysic) {
        unitPhysic->view->removeFromParent();
        unitList.remove_if([&](const std::shared_ptr<UnitPhysic> &o) {
            return o == unitPhysic;
        });
    }

    void update(double dt) {
        dt *= 10;
        for (auto &p : unitList) {
            p->update(dt, map);
        }

        unitList.remove_if([](const std::shared_ptr<UnitPhysic> &o) { return o->isDead; });
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
    }

    static std::vector<std::vector<unsigned char>> createMap(type::Vector<int> mapSize) {
        auto fNoiseSeed = std::vector<double>(static_cast<int>(mapSize.x));
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
            }
        }
        return map;
    }

    static std::vector<double> PerlinNoise1D(std::vector<double> fSeed, int nOctaves, double fBias);
	void handleNetworkCmd(CMD cmd, Params& params) {

	}
};

#endif //WORM_MAPLOGIC_H
