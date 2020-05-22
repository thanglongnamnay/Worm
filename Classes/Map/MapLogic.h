//
// Created by long on 22/05/2020.
//

#ifndef WORM_MAPLOGIC_H
#define WORM_MAPLOGIC_H

#include <Types/Vector.h>
#include <vector>
#include "type_safe/integer.hpp"


class MapLogic {
private:
    Vector<int> mapSize;
    std::vector<std::vector<u_char>> map;

    void CreateMap();
    static std::vector<float> PerlinNoise1D(std::vector<float> fSeed, int nOctaves, float fBias);
};


#endif //WORM_MAPLOGIC_H
