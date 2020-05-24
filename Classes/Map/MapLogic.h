//
// Created by long on 22/05/2020.
//

#ifndef WORM_MAPLOGIC_H
#define WORM_MAPLOGIC_H

#include <Types/Vector.h>
#include <vector>
#include "MapView.h"


class MapLogic {
private:
    type::Vector<int> mapSize;
    std::vector<std::vector<unsigned char>> map;
public:
    MapView* mapView;
    explicit MapLogic(type::Vector<int> mapSize);
    MapLogic(MapLogic&& rhs) noexcept : mapSize(rhs.mapSize)
    , map(std::move(rhs.map))
    , mapView(rhs.mapView) {}

private:
    static std::vector<std::vector<unsigned char>> createMap(type::Vector<int> mapSize) {
        auto fNoiseSeed = std::vector<float>(static_cast<int>(mapSize.x));
        for (int i = 0; i < mapSize.x; i++)
            fNoiseSeed[i] = (float)rand() / RAND_MAX;
        fNoiseSeed[0] = 0.5f;
        auto fSurface = PerlinNoise1D(fNoiseSeed, 8, 2.0f);
        std::vector<std::vector<unsigned char>> map(mapSize.y);
        for (auto y = 0; y < mapSize.y; ++y) {
            map[y] = std::vector<unsigned char>(mapSize.x);
            for (auto x = 0; x < mapSize.x; ++x) {
                map[y][x] = y >= fSurface[x] * mapSize.y;
            }
        }
        return map;
    }

    static std::vector<float> PerlinNoise1D(std::vector<float> fSeed, int nOctaves, float fBias);
};


#endif //WORM_MAPLOGIC_H
