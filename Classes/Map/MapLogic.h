//
// Created by long on 22/05/2020.
//

#ifndef WORM_MAPLOGIC_H
#define WORM_MAPLOGIC_H

#include <Types/Vector.h>
#include <vector>
#include <Units/UnitPhysic.h>
#include "MapView.h"

class MapLogic {
private:
    type::Vector<int> mapSize;
    std::vector<std::vector<unsigned char>> map;
    std::list<std::shared_ptr<UnitLogic>> unitList;
    std::shared_ptr<Worm> worm;
public:
    MapView* mapView;

    explicit MapLogic(type::Vector<int> mapSize);

    MapLogic(MapLogic&& rhs) noexcept
            :mapSize(rhs.mapSize), map(std::move(rhs.map)), mapView(rhs.mapView) {
    }

    void addUnit(const std::shared_ptr<UnitLogic>& unitLogic) {
        unitLogic->draw();
        mapView->addChild(unitLogic->view);
        unitList.push_back(unitLogic);
    }

    void update(double dt) {
    	dt *= 10;
        for (auto& p : unitList) {
            p->update(dt, map);
        }

        // Remove dead objects from the list, so they are not processed further. As the object
        // is a unique pointer, it will go out of scope too, deleting the object automatically. Nice :-)
        unitList.remove_if([](std::shared_ptr<UnitLogic>& o) { return o->isDead; });
    }

private:
    static std::vector<std::vector<unsigned char>> createMap(type::Vector<int> mapSize) {
        auto fNoiseSeed = std::vector<double>(static_cast<int>(mapSize.x));
        srand(time(0));
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
