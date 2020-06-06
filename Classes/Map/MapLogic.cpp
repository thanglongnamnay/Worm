//
// Created by long on 22/05/2020.
//

#include "MapLogic.h"

#include <utility>

std::vector<double> MapLogic::PerlinNoise1D(std::vector<double> fSeed, int nOctaves, double fBias) {
	auto nCount = fSeed.size();
	std::vector<double> fOutput(nCount);
	for (auto x = 0; x<nCount; x++) {
		auto fNoise = 0.0f;
		auto fScaleAcc = 0.0f;
		auto fScale = 1.0f;

		for (auto o = 0; o<nOctaves; o++) {
			auto nPitch = nCount >> o;
			auto nSample1 = (x/nPitch)*nPitch;
			auto nSample2 = (nSample1+nPitch)%nCount;
			auto fBlend = (double)(x-nSample1)/(double)nPitch;
			auto fSample = (1.0f-fBlend)*fSeed[nSample1]+fBlend*fSeed[nSample2];
			fScaleAcc += fScale;
			fNoise += fSample*fScale;
			fScale = fScale/fBias;
		}
		fOutput[x] = fNoise/fScaleAcc;
	}
	return fOutput;
}

MapLogic::MapLogic(type::Vector<int> mapSize)
		:mapSize(mapSize) {
	map = createMap(mapSize);
	mapView = MapView::create(map);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Worm/texture.plist", "Worm/texture.png");\
//	for (auto i = 0; i < 10; ++i) {
		addUnit(std::make_unique<Worm>(300, 400));
//	}
	mapView->schedule([=](float dt) {
	  this->update(dt);
	}, 0.0f, "update");
}