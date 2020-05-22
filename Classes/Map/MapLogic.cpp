//
// Created by long on 22/05/2020.
//

#include "MapLogic.h"

void MapLogic::CreateMap() {
    auto fNoiseSeed = std::vector<float>(mapSize.x);
    for (int i = 0; i < mapSize.x; i++)
        fNoiseSeed[i] = (float)rand() / RAND_MAX;
    fNoiseSeed[0] = 0.5f;
    auto fSurface = PerlinNoise1D(fNoiseSeed, 8, 2.0f);
    for (int x = 0; x < mapSize.x; x++) {
        for (int y = 0; y < mapSize.y; y++) {
            map[y][x] = y >= fSurface[x] * mapSize.y ? 1 : 0;
        }
    }
}

std::vector<float> MapLogic::PerlinNoise1D(std::vector<float> fSeed, int nOctaves, float fBias) {
    auto nCount = fSeed.size();
    std::vector<float> fOutput(nCount);
    for (auto x = 0; x < nCount; x++)
    {
        auto fNoise = 0.0f;
        auto fScaleAcc = 0.0f;
        auto fScale = 1.0f;

        for (auto o = 0; o < nOctaves; o++)
        {
            auto nPitch = nCount >> o;
            auto nSample1 = (x / nPitch) * nPitch;
            auto nSample2 = (nSample1 + nPitch) % nCount;
            auto fBlend = (float)(x - nSample1) / (float)nPitch;
            auto fSample = (1.0f - fBlend) * fSeed[nSample1] + fBlend * fSeed[nSample2];
            fScaleAcc += fScale;
            fNoise += fSample * fScale;
            fScale = fScale / fBias;
        }
        fOutput[x] = fNoise / fScaleAcc;
    }
    return fOutput;
}
